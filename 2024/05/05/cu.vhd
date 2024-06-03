
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity cu is
Port (rst	:in STD_LOGIC;
		clk	:in STD_LOGIC;
		clk0	:in STD_LOGIC;
		instructions :in STD_LOGIC_VECTOR (15 downto 0);
		light:out STD_LOGIC_VECTOR(15 downto 0);
		showCtrl:in std_logic;
		bZero_ctrl:in std_logic;
		stateCnt1 : out STD_LOGIC_VECTOR (6 downto 0);
		stateCnt2 : out std_logic_vector ( 6 downto 0)
		);
end cu;

architecture Behavioral of cu is
	signal bzero:std_logic;
	type shower_state is (PC,ALU,Mem,Reg);
	signal shower:shower_state;
	type controler_state is (instruction_fetch,decode,execute,mem_control,write_reg);
	signal state: controler_state;
	signal PCWrite:std_logic;
	signal PCWriteCond :std_logic;
	signal PCSource:std_logic;
	signal ALUOp:std_logic_vector(1 downto 0);
	signal ALUSrcA:std_logic;
	signal ALUSrcB:std_logic_vector(1 downto 0);
	signal MemRead:std_logic;
	signal MemWrite:std_logic;
	signal IRWrite :std_logic;
	signal MemtoReg :std_logic_vector(1 downto 0);
	signal RegWrite: std_logic_vector(2 downto 0);
	signal RegDst:std_logic_vector(1 downto 0);
	signal IorD:std_logic;
	signal tmpb_zero:std_logic;
	signal tmp_light :std_logic_vector(15 downto 0);
	
Begin

	-- stateCnt说明:
	-- stateCnt1显示机器周期: 0:Fetch, 1:Decode, 2:Execute, 3:MemCtrl, 4:WrintReg
	-- stateCnt2显示各部件的控制信号: 3:PC, 0:ALU, 1:Mem, 2:Reg

	-- 请务必配合电子书《计算机硬件系统实验教程扫描版清华大学出版社》实验5.9一起看


	light<=tmp_light;
	
	process(clk,rst,showCtrl)
	begin
		if rst='0' then
			shower<=PC;
			stateCnt2 <= "1111111";
		elsif showCtrl'event and showCtrl = '1' then
			case shower is
				when PC=>
				stateCnt2 <= "0111111";
				shower<=ALU;
				when ALU=>
				stateCnt2 <= "0000110";
				shower<=Mem;
				when Mem=>
				stateCnt2 <= "1011011";
				shower<=Reg;
				when Reg=>
				stateCnt2 <= "1001111";
				shower<=PC;
			end case;
		end if;  
	end process;
		
	process(clk0,rst,state)
	begin
		if rst='0' then
			tmp_light<=x"AAAA";
		elsif rising_edge(clk0) then
			case shower is
				when PC=>
					tmp_light(15 downto 0)<=x"0000";
					tmp_light(15)<=PCWrite;
					tmp_light(11)<=PCSource;
					tmp_light(7)<=PCWriteCond;
				when ALU=>
					tmp_light(15 downto 0)<=x"0000";
					tmp_light(15 downto 14)<=ALUOp;
					tmp_light(11)<=ALUSrcA;
					tmp_light(7 downto 6)<=ALUSrcB;
				when Mem=>
					tmp_light(15 downto 0)<=x"0000";
					tmp_light(15)<=MemRead;
					tmp_light(11)<=MemWrite;
					tmp_light(7)<=IRWrite;
					tmp_light(3 downto 2)<=MemtoReg;
				when Reg=>
					tmp_light(15 downto 0)<=x"0000";
					tmp_light(15 downto 13)<=RegWrite;
					tmp_light(11 downto 10)<=RegDst;
					tmp_light(7)<=IorD;
			end case;
		end if;
	end process;
	
	process(rst,bZero_Ctrl)
		begin
		if rst='0' then
			bzero<='0';
		elsif bZero_Ctrl'event and bZero_Ctrl = '1' then
			if bzero='0' then
				bzero<='1';
				tmpb_zero<='0';
			elsif bzero='1' then
				tmpb_zero<='1';
				bzero<='0';
			end if;
		end if;
	end process;
	
	process(bzero)
		begin
		if bzero='1' then
			PCWriteCond<='1';
		elsif bzero='0' then
			PCWriteCond<='0';
		end if;
	end process;
	
	process(rst,clk)
		begin
		if(rst='0') then
			state<=instruction_fetch;
			IorD<='0';
			IRWrite<='0';
			MemRead<='0';
			MemWrite<='0';
			MemtoReg<="00";
			ALUOp<="00";
			ALUSrcA<='0';
			ALUSrcB<="00";
			PCWrite<='0';
			PCSource<='0';
			RegDst<="00";
			RegWrite<="000";
			stateCnt1 <= "1111111";
		elsif clk'event and clk = '1' then
			case state is
				when instruction_fetch=> stateCnt1 <= "0111111";
					MemRead<='1';
					ALUSrcA<='0';
					IorD<='0';
					ALUSrcB<="01";
					ALUOp<="00";
					PCWrite<='1';
					PCSource<='0';
					IRWrite<='1';
					RegWrite<="000";
					state<=decode;
				when decode=> stateCnt1 <= "0000110";
					IRWrite<='0'; 
					MemRead<='0';
					PCWrite<='0';
					ALUSrcA<='0';
					ALUSrcB<="10";
					ALUOp<="00";
					state<=execute;
				when execute=> stateCnt1 <= "1011011";
					case instructions(15 downto 11)is
						when"00100"=>
							-------------BEO2
							ALUSrcA<='1';
							ALUOp<="10";
							PCSource<='1';
							state<=instruction_fetch;
						when"10011"=>
							-------------LW
							ALUSrcA<='1';
							ALUSrcB<="10";
							ALUOp<="00";
							state<=mem_control;
						when"11011"=>
							--SW
							ALUSrcA<='1';
							ALUSrcB<="10";
							ALUOp<="00";
							state<=mem_control;
						when"11100"=>
							case instructions(1 downto 0)is
								when"01"=>
									--------ADDU
									ALUSrcA<='1';
									ALUSrcB<="00";
									ALUOp<="00";
								when"11"=>
									---SUBU
									ALUSrcA<='1';
									ALUSrcB<="00";
									ALUOp<="01";
								when others=>
									null;
							end case;
						state<=write_reg;
						when"11101"=>
							case instructions(4 downto 0)is
								when"01101"=>
									-------OR
									ALUSrcA<='1';
									ALUSrcB<="00";
									ALUOp<="10";
									state<=write_reg;
								when"00000"=>
									case instructions(7 downto 5)is
										when"000"=>
											----JR
											ALUSrcA<='1';
											ALUOp<="10";
											PCWrite<='1';
											PCSource<='0';
											state<=instruction_fetch;
										when others=>
											null;
									end case;
								when others=>
									null;
							end case;
						when others=>
							null;
					end case;
				when mem_control=> stateCnt1 <= "1001111";
					PCWrite<='0';
					RegWrite<="000";
					case instructions(15 downto 11) is
						when"10011"=>
							-------------LW
							MemRead<='1';
							IorD<='1';
							state<=write_reg;
						when"11011"=>
							-------------SW
							MemWrite<='1';
							IorD<='1';
							state<=write_reg;
						when others=>
							null;
					end case;
				when write_reg=> stateCnt1 <= "1100110";
					MemWrite<='0';
					MemRead<='0';
					case instructions(15 downto 11) is
						when"10011"=>
						-------------LW
							RegDst<="10";
							RegWrite<="001";
							MemtoReg<="01";
						when"11011"=>
							------------- SW
							MemWrite<='0';
							IorD<='0';
						when"11100"=>
							case instructions(1 downto 0)is
								when"01"=>
									-------------ADDU
									RegDst<="01";
									RegWrite<="001";
									MemtoReg<="00";
								when"11"=>
									-------------SUBU
									RegDst<="01";
									RegWrite<="001";
									MemtoReg<="00";
								when others=>
									null;
							end case;
						when"11101"=>
							case instructions(4 downto 0)is
								when"01101"=>
									------------OR
									RegDst<="00";
									RegWrite<="001";
									MemtoReg<="00";
								when others=>
									null;
							end case;
						when others=>
							null;
					end case;
					state<=instruction_fetch;
			end case;
		end if;
	end process;
end Behavioral;
