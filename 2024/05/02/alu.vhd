library IEEE;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity alu is
	Port ( 
		CLK     : in STD_LOGIC; -- 时钟信号，切换状态机
		RST     : in STD_LOGIC; -- 复位信号，切换至初始状态机
		INPUT   : in  STD_LOGIC_VECTOR (15 downto 0); -- 输入数据
		OUTPUT  : out STD_LOGIC_VECTOR (15 downto 0); -- 输出数据
		stateCnt: out STD_LOGIC_VECTOR (6  downto 0)  -- state的7段数码管数字
	);
end entity alu;

architecture Behavioral of alu is

	signal state	: integer range 0 to 4;	-- 状态机序号
	signal a, b, y	: std_logic_vector (15 downto 0); -- a b存放输入信号, y用于输出
	signal y_17bits: std_logic_vector (16 downto 0); -- 用于生成flag
	signal opCode	: std_logic_vector (3  downto 0); -- 操作码
	signal cin		: std_logic_vector (15 downto 0); -- carry-in, 用vecotr存储便于后续操作
	signal zF    	: std_logic; -- zero     flag
	signal cF    	: std_logic; -- carry    flag
	signal sF    	: std_logic; -- sign  	 flag
	signal overF 	: std_logic; -- overflow flag
	signal cout  	: std_logic; -- carry-out, 只是表示加减法运算的最高位进位
	constant zero	: std_logic_vector(15 downto 0) := (others => '0'); -- 常量0

begin

process(RST, CLK)
begin
	if RST = '0' then 
		state <= 0; a <= (others=>'0'); b <= (others=>'0'); opCode <= (others=>'0'); 
		output <= (others=>'0'); stateCnt <= (others=>'1'); cin    <= (others=>'0');
	elsif CLK'event and CLK = '1' then
		case state is
		
			-- if state == 8, then input a
			-- if state == 0, then input b 					(a is stored)
			-- if state == 1, then input opCode and cin 	(b is stored)
			-- if state == 2, then calcuate over 			(output is ready)
			-- if state == 3, then OUTPUT
			-- if state == 4, then optput Flags and input a
			
			when 0 => state <= 1; stateCnt <= not "1000000";
				if (INPUT /= zero) then a <= INPUT; end if;	-- 只在input有效(不为0)时更新值
				OUTPUT <= (others=>'0');
			when 1 => state <= 2; stateCnt <= not "1111001";
				if (INPUT /= zero) then b <= INPUT; end if;	-- 只在input有效(不为0)时更新值
				OUTPUT <= a;
			when 2 => state <= 3; stateCnt <= not "0100100";
				cin <= (0=>input(15), others=>'0'); opCode <= input(3 downto 0); 
				OUTPUT <= b;
			when 3 => state <= 4; stateCnt <= not "0110000";
				OUTPUT <= y;
			when 4 => state <= 0; stateCnt <= not "0011001";
				OUTPUT <= (0=>cF, 1=>sF, 2=>overF, 3=>zF, 4=>cout, others=>'0');
				
		end case;
	end if;
end process;
	
process(RST, opCode)

	variable ub: unsigned(15 downto 0) := unsigned(b); -- unsigned b_value
	
begin
	cF <= '0'; sF <= '0'; zF <= '0'; overF <= '0'; cout <= '0';
	case opCode is
		-- 下列标志位设置参考《汇编语言 基于x86处理器》
		
		-- 加减法影响全部标志位 + 产生Cout
		when "0000"	=> -- Add
			y        <= a + b + cin;
			y_17bits <= ('0' & a) + ('0' & b); -- 仅y(16)是y的最高位进位信号, 其余都不是,下省略注释
			cout     <= y_17bits(16);
			sF       <= y(15);
			cF       <= y_17bits(16) xor '0';
			overF    <= (a(15) AND b(15) AND (not y(15))) OR ((not a(15)) AND (not b(15)) AND y(15));
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		when "0001"	=> -- Sub
			y        <= a + (not b) + 1;
			y_17bits <= ('0' & a) + ('0' & (not b)) + 1;
			cout     <= y_17bits(16);
			sF       <= y(15);
			cF       <= y_17bits(16) xor '1';
			overF    <= (a(15) AND (not b(15)) AND (not y(15))) OR ((not a(15)) AND b(15) AND y(15));
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		when "0010"	=> -- ADC
			y        <= a + b + cin;
			y_17bits <= ('0' & a) + ('0' & b) + ('0' & cin);
			cout     <= y_17bits(16);
			sF       <= y(15);
			cF       <= y_17bits(16) xor '0';
			overF    <= (a(15) AND b(15) AND (not y(15))) OR ((not a(15)) AND (not b(15)) AND y(15));
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		when "0011"	=> -- SBB
			y        <= a + (not b) + 1 + (not cin) + 1;
			y_17bits <= ('0' & a) + ('0' & ((not b) + 1)) + ('0' & ((not cin) + 1));
			cout     <= y_17bits(16);
			sF       <= y(15);
			cF       <= y_17bits(16) xor '1';
			overF    <= (a(15) AND (not b(15)) AND (not y(15))) OR ((not a(15)) AND b(15) AND y(15));
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		-- 逻辑运算影响一部分标志位 ( SF, ZF )
		when "0100" => -- AND
			y        <= a AND b;
			sF       <= y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
		when "0101" => -- OR
			y        <= a or b;
			sF       <= y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
		when "0110" => -- XOR
			y        <= a xor b;
			sF       <= y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
		when "0111" => -- not
			y        <= not a; -- 不影响标志位
		
		-- 逻辑/算数移位运算影响所有标志位
		when "1000" => -- SLL
			y        <= std_logic_vector(unsigned(a) sll to_integer(ub));
			y_17bits <= to_stdlogicvector(to_bitvector('0' & a) sll to_integer(ub));
			cF       <= y_17bits(16);
			sF       <= y(15);
			overF    <= a(15) xor y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		when "1001" => -- SRL
			y        <= std_logic_vector(unsigned(a) srl to_integer(ub));
			y_17bits <= to_stdlogicvector(to_bitvector(a & '0') srl to_integer(ub));
			cF       <= y_17bits(0);
			sF       <= y(15);
			overF    <= a(15) xor y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		when "1010" => -- SLA
			y        <= std_logic_vector(unsigned(a) sll to_integer(ub));
			y_17bits <= to_stdlogicvector(to_bitvector('0' & a) sll to_integer(ub));
			cF       <= y_17bits(16);
			sF       <= y(15);
			overF    <= a(15) xor y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		when "1011" => -- SRA
			y        <= to_stdlogicvector(to_bitvector(a) sra to_integer(ub));
			y_17bits <= to_stdlogicvector(to_bitvector(a & '0') sra to_integer(ub));
			cF       <= y_17bits(0);
			sF       <= y(15);
			overF    <= a(15) xor y(15);
			if y = zero then zF <= '1'; else zF <= '0'; end if;
			
		-- 逻辑循环移位影响部分标志位 ( CF, OF )
		when "1100" => -- ROL
			y        <= std_logic_vector(unsigned(a) rol to_integer(ub));
			cf       <= y(0);
			overF    <= a(15) xor y(15);
			
		when "1101" => -- ROR
			y        <= std_logic_vector(unsigned(a) ror to_integer(ub));	
			cf       <= y(15);
			overF    <= a(15) xor y(15);
			
		when others=>  y <= (others=>'0');
		
	end case;
end process;

end Behavioral;