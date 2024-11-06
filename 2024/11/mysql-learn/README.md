# MySQL

### 目录

- [x] 在服务器上部署 MySQL
- [x] 与MySQL服务器的交互方式
- [x] 用户设置
- [x] 改变MySQL密码等级
- [x] 简单尝试MySQL



### 一、在服务器上部署 MySQL

在服务器上部署 MySQL 以及在主机上与 MySQL 服务器进行交互的过程，通常分为以下几个步骤。这里假设你使用的是 Ubuntu Linux 系统，并且需要通过网络远程访问数据库。

#### 1. **更新包列表**

首先，确保你的系统是最新的，并且更新包管理器列表：

```bash
sudo apt update
```

#### 2. **安装 MySQL 服务器**

接着，安装 MySQL 服务器：

```bash
sudo apt install mysql-server
```

在安装过程中，系统会自动安装 MySQL 服务器及其相关组件。

#### 3. **启动 MySQL 服务**

安装完成后，MySQL 服务通常会自动启动。你可以使用以下命令确认 MySQL 服务是否已启动：

```bash
sudo systemctl status mysql
```

如果 MySQL 服务没有启动，可以使用下面的命令手动启动它：

```bash
sudo systemctl start mysql
```

为了确保 MySQL 服务在系统启动时自动启动，可以执行：

```bash
sudo systemctl enable mysql
```

#### 4. **进行安全配置**

MySQL 提供了一个安全配置工具来帮助你进行初步的安全设置。运行下面的命令：

```bash
sudo mysql_secure_installation
```

该工具会引导你设置 root 用户的密码，删除测试数据库，禁用远程 root 登录，并加强其他安全设置。

#### 5. **配置 MySQL 允许远程连接**

默认情况下，MySQL 只允许从本地（localhost）连接。如果你想要从其他机器访问数据库，需要修改 MySQL 配置文件。

1. 编辑 MySQL 配置文件（`/etc/mysql/mysql.conf.d/mysqld.cnf`）：

```bash
sudo vim /etc/mysql/mysql.conf.d/mysqld.cnf
```

2. 找到并修改 `bind-address` 行：

```bash
bind-address = 0.0.0.0
```

将 `0.0.0.0` 设置为允许来自任何 IP 地址的连接。如果你只想允许某个特定 IP 地址访问，可以将 `0.0.0.0` 改为该 IP 地址。

3. 重启 MySQL 服务以应用配置更改：

```bash
sudo systemctl restart mysql
```

#### 6. **开放 MySQL 端口**

如果你在使用云服务器（如 AWS、阿里云等），需要确保防火墙允许通过 MySQL 的默认端口（3306）访问。

在 Ubuntu 上，你可以使用 `ufw` 工具开放端口：

```bash
sudo ufw allow 3306
```

可以使用以下命令检查 MySQL 是否在监听 3306 端口：

```bash
sudo netstat -plnt | grep 3306
```

如果你的服务器没有安装 `ufw`，你需要直接配置服务器的防火墙或者安全组，允许 TCP 端口 3306 的访问。

不仅如此，还需要在云服务器提供商的控制页面中，配置相关防火墙。



### 二、与MySQL服务器的交互方式

与 MySQL Server 进行交互有多种方式，每种方式适用于不同的场景或需求。主要的交互方式包括：

#### 1. 命令行客户端（MySQL Client）

1. **MySQL 命令行工具**
   - **用途**：这是最基本、最常用的交互方式，可以直接在终端中与 MySQL 数据库进行交互，执行 SQL 查询、管理数据库和用户等操作。
   - **使用方法**：
     - 通过命令行连接到 MySQL 服务器：
       ```bash
       mysql -u username -p -h host -P port database_name
       ```
       其中：
       - `-u`：指定用户名。
       - `-p`：提示输入密码。
       - `-h`：指定服务器 IP 地址（默认为 `localhost`）。
       - `-P`：指定 MySQL 服务端口（默认为 3306）。
       - `database_name`：指定要连接的数据库。
   
     - 连接成功后，你将进入 MySQL 命令行环境，开始执行 SQL 查询：
       ```sql
       SELECT * FROM users;
       ```

   - **优点**：轻量、快速、适合快速执行简单查询和数据库管理操作。
   - **缺点**：没有图形界面，适合有一定命令行基础的用户。

2. **MySQL 客户端（`mysql`）**
   - MySQL 客户端是通过命令行直接与 MySQL Server 进行交互的标准工具。
   - 它不仅可以执行 SQL 语句，还可以用于数据库管理、配置调整、查看日志等。

#### 2. 图形化界面工具

1. **MySQL Workbench**
   - **用途**：MySQL 官方提供的图形化管理工具，支持数据库设计、SQL 查询、数据迁移、备份、服务器监控等多种功能。
   - **特点**：
     - 支持创建、编辑数据库、表、视图、存储过程等。
     - 可以执行 SQL 查询并查看结果。
     - 可视化地管理数据库结构和索引。
     - 支持数据库备份与恢复。
   
   - **使用方法**：下载并安装 MySQL Workbench，配置连接信息（如服务器 IP、用户名、密码、端口等），然后通过图形界面与数据库交互。

2. **phpMyAdmin**
   - **用途**：一个基于 Web 的 MySQL 管理工具，通常通过浏览器访问。它是一个开源工具，适合用于 Web 环境下的 MySQL 管理。
   - **特点**：
     - 提供 Web 界面，可以通过浏览器轻松管理 MySQL 数据库。
     - 支持 SQL 查询执行、用户管理、表结构设计、备份恢复等功能。
     - 适合没有命令行经验的用户。

   - **使用方法**：安装并配置 phpMyAdmin，在浏览器中访问，通过 Web 界面连接和管理 MySQL 数据库。

3. **DBeaver**
   - **用途**：一个多数据库支持的图形化数据库管理工具，不仅支持 MySQL，还支持 PostgreSQL、Oracle、SQLite 等其他数据库系统。
   - **特点**：
     - 提供 SQL 编辑器、查询结果查看、数据库结构浏览、导入导出数据等功能。
     - 开源并且免费，适用于跨平台环境（Windows、Mac、Linux）。

   - **使用方法**：下载并安装 DBeaver，配置 MySQL 连接，便可以通过图形化界面进行数据库管理。

#### 3. 编程语言接口（程序化交互）

1. **Python（MySQL Connector）**
   - **用途**：使用 Python 与 MySQL 数据库进行交互，常用于 Web 应用程序、数据分析等项目。
   - **使用方法**：安装 MySQL Connector，使用 Python 代码进行数据库操作：
     ```python
     import mysql.connector
     
     conn = mysql.connector.connect(
         host='hostname',
         user='username',
         password='password',
         database='database_name'
     )
     
     cursor = conn.cursor()
     cursor.execute("SELECT * FROM users")
     result = cursor.fetchall()
     
     for row in result:
         print(row)
     
     conn.close()
     ```

2. **Java（JDBC）**
   - **用途**：Java 应用程序可以通过 JDBC（Java Database Connectivity）与 MySQL 进行交互。适用于构建大型企业级应用。
   - **使用方法**：使用 JDBC 驱动连接到 MySQL，执行 SQL 查询。
     ```java
     import java.sql.*;
     
     public class MySQLExample {
         public static void main(String[] args) {
             try {
                 Connection conn = DriverManager.getConnection("jdbc:mysql://hostname:3306/database_name", "username", "password");
                 Statement stmt = conn.createStatement();
                 ResultSet rs = stmt.executeQuery("SELECT * FROM users");
     
                 while (rs.next()) {
                     System.out.println(rs.getString("name"));
                 }
     
                 conn.close();
             } catch (SQLException e) {
                 e.printStackTrace();
             }
         }
     }
     ```

3. **PHP（MySQLi 或 PDO）**
   - **用途**：PHP 与 MySQL 的结合非常常见，尤其是在 Web 开发中。PHP 可以通过 MySQLi 或 PDO 接口与 MySQL 数据库交互。
   - **使用方法**：
     - 使用 MySQLi：
       ```php
       <?php
       $conn = new mysqli("hostname", "username", "password", "database_name");
       
       if ($conn->connect_error) {
           die("Connection failed: " . $conn->connect_error);
       }
       
       $sql = "SELECT * FROM users";
       $result = $conn->query($sql);
       
       if ($result->num_rows > 0) {
           while($row = $result->fetch_assoc()) {
               echo "id: " . $row["id"]. " - Name: " . $row["name"]. "<br>";
           }
       } else {
           echo "0 results";
       }
       
       $conn->close();
       ?>
       ```

   - **优点**：适用于 Web 应用，轻量且集成方便。

#### 4. 其他工具和方法

1. **Navicat for MySQL**
   - **用途**：Navicat 是一个商业数据库管理工具，支持 MySQL、MariaDB、PostgreSQL、Oracle 等数据库的管理。它提供强大的图形化界面，可以进行数据库管理、备份、查询优化等工作。
   - **优点**：功能全面，支持数据库的备份恢复、数据导入导出、查询设计等。

2. **命令行工具（`mysqldump` 和 `mysqladmin`）**
   - **用途**：除了交互式的 MySQL 客户端，MySQL 还提供了一些命令行工具用于管理和备份数据库。
     - **`mysqldump`**：用于导出数据库或表的数据。
     - **`mysqladmin`**：用于管理 MySQL 服务器（如启动、停止、检查状态、查看配置信息等）。

   - **使用例子**：
     - 使用 `mysqldump` 导出数据库：
       ```bash
       mysqldump -u username -p database_name > backup.sql
       ```
     - 使用 `mysqladmin` 检查 MySQL 状态：
       ```bash
       mysqladmin -u root -p status
       ```

#### 总结

与 MySQL 服务器的交互方式主要包括：
- **命令行工具**：适用于快速执行 SQL 查询和管理操作（如 `mysql` 客户端）。
- **图形化界面工具**：如 MySQL Workbench、phpMyAdmin、DBeaver 等，适合需要可视化管理的场景。
- **编程语言接口**：如 Python、Java、PHP 等，适合开发者在应用程序中与数据库交互。
- **其他工具**：如 Navicat、`mysqldump` 和 `mysqladmin` 等工具，用于数据库管理、备份、恢复等。

选择哪种方式取决于你的需求、开发环境以及数据库管理的复杂性。



### 三、用户设置

#### 1. root用户设置

虽然 MySQL 安装后没有为 `root` 用户设置密码，这意味着你可以通过本地主机直接以 `root` 用户身份登录 MySQL 而不需要密码。但出于安全考虑，建议为 `root` 设置密码。

1. **以 root 用户登录 MySQL（一开始没有密码）**

   由于 `root` 用户没有密码，你可以通过以下命令直接登录 MySQL：

   ```bash
   sudo mysql -u root
   ```

   这样会自动使用 `sudo` 提升权限，并以 `root` 用户身份登录 MySQL。你会进入 MySQL 命令行界面，类似以下的输出：

   ```sql
   Welcome to the MySQL monitor.  Commands end with ; or \g.
   Your MySQL connection id is 7
   Server version: 8.0.x MySQL Community Server - GPL

   Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

   mysql>
   ```

2. **为 root 用户设置密码（推荐）**

   为了增强 MySQL 的安全性，强烈建议为 `root` 用户设置密码。你可以使用以下步骤设置密码：

   - 登录到 MySQL：

     ```bash
     sudo mysql -u root
     ```

   - 在 MySQL 命令行界面，使用以下 SQL 语句为 `root` 用户设置密码（假设你想设置密码为 `new_password`）：

     ```sql
     ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'new_password';
     FLUSH PRIVILEGES;
     ```

   - 这将为 `root` 用户设置一个新的密码 `new_password`，并使修改生效。

3. **使用新密码登录**

   现在你可以使用新的密码登录 MySQL 了：

   ```bash
   mysql -u root -p
   ```

   系统会提示你输入密码，输入刚才设置的新密码（`new_password`）。

#### 2. 普通用户设置

你可以通过以下步骤创建一个新用户并赋予其远程访问权限。这样可以在保持 `root` 用户仅限本地登录的同时，创建一个专门用于远程连接的用户。

1. 登录到 MySQL

   首先，使用 `root` 用户登录 MySQL 命令行：

   ```bash
   sudo mysql -u root
   ```

2. 创建新用户

   假设你想创建一个用户名为 `remote_user`，密码为 `your_password` 的用户。可以使用以下 SQL 语句：

   ```sql
   CREATE USER 'remote_user'@'%' IDENTIFIED BY 'your_password';
   ```

   - **解释**：这里的 `'%'` 代表允许该用户从任意 IP 地址进行连接。如果只希望允许特定 IP 地址连接，可以将 `%` 替换为指定的 IP，比如 `192.168.1.100`。

3. 为新用户赋予权限

   接下来，为 `remote_user` 赋予访问 `test_db` 数据库的权限。如果你希望用户能够操作所有数据库，可以改为 `*.*`：

   ```sql
   GRANT ALL PRIVILEGES ON test_db.* TO 'remote_user'@'%';
   ```

   这样，该用户将拥有 `test_db` 数据库的所有权限（查询、插入、更新、删除等）。

   如果你希望限制用户的权限，只授予特定的操作权限，可以用类似以下的语句：

   ```sql
   GRANT SELECT, INSERT, UPDATE, DELETE ON test_db.* TO 'remote_user'@'%';
   ```

4. 刷新权限

   执行以下命令使更改生效：

   ```sql
   FLUSH PRIVILEGES;
   ```

5. 退出 MySQL 并测试连接

   输入 `exit` 退出 MySQL，然后在你的客户端上测试新用户的连接：

   ```bash
   mysql -h <服务器IP> -u remote_user -p
   ```

   系统会提示你输入 `your_password`，成功登录后可以进行相应操作了。

##### 其他建议

- **安全性**：建议为新用户选择一个强密码，并尽量限制用户权限，不给予超出需要的权限。
- **防火墙**：确保 3306 端口的入站规则仅对信任的 IP 开放，避免安全风险。



### 四、如何改变MySQL密码等级

```sudo mysql_secure_installation```中初始化了密码等级，但如何修改它呢？

MySQL 使用 `validate_password` 插件来控制密码的安全性，你可以通过设置该插件的相关参数来调整密码的复杂度要求。以下是调整密码等级的步骤：**（可跳转至步骤5）**

1. 登录到 MySQL

   首先，用 `root` 用户或有足够权限的用户登录 MySQL：

   ```bash
   sudo mysql -u root
   ```

2. 检查当前密码策略

   可以使用以下命令查看当前的密码策略等级：

   ```sql
   SHOW VARIABLES LIKE 'validate_password.%';
   ```

   这会输出 `validate_password` 插件的相关配置，关键字段包括：

   - **validate_password_policy**：密码的策略等级
   - **validate_password_length**：密码最小长度
   - **validate_password_mixed_case_count**、**validate_password_number_count**、**validate_password_special_char_count**：分别控制混合大小写、数字和特殊字符的数量要求

3. 设置密码等级（validate_password_policy）

   MySQL 提供了 4 个等级的密码策略，可以根据需求选择：

   - **0 or LOW**：仅要求密码长度符合 `validate_password_length` 设置的要求。
   - **1 or MEDIUM**：密码需要包含字母、数字和特殊字符。
   - **2 or STRONG**：密码需要包含字母、数字、特殊字符，并且满足混合大小写的要求。
   - **3 or VERY STRONG**：要求极为严格的密码策略。

4. 自行设置密码要求

   ```sql
   SET GLOBAL validate_password.length = 10;            -- 设置最小长度为 10
   SET GLOBAL validate_password.mixed_case_count = 1;   
   												-- 至少包含一个大写和小写字母
   SET GLOBAL validate_password.number_count = 1;       -- 至少包含一个数字
   SET GLOBAL validate_password.special_char_count = 1; -- 至少包含一个特殊字符
   ```

5. **使设置永久生效**

   直接在 MySQL 中设置的参数会在 MySQL 重启后失效。要让配置永久生效，可以将设置写入 MySQL 配置文件。

   打开 MySQL 配置文件（通常是 `/etc/mysql/mysql.conf.d/mysqld.cnf`），并添加以下内容：

   ```ini
   [mysqld]
   validate_password.policy = 0
   validate_password.length = 8
   validate_password.mixed_case_count = 1
   validate_password.number_count = 1
   validate_password.special_char_count = 0
   ```

   保存配置文件后，重启 MySQL 使设置生效：

   ```bash
   sudo systemctl restart mysql
   ```
6. 小结

   通过调整 `validate_password` 插件的相关参数，你可以灵活控制密码的复杂度和安全性，选择适合你的项目和用户的密码强度等级。



### 五、简单尝试MySQL

恭喜成功连接上数据库！现在你可以在 `test_db` 中进行一系列的操作，比如创建表、插入数据、查询数据等。以下是一些常见的基本操作：

#### 1. **创建表**

首先，可以创建一个表。例如，我们创建一个简单的用户表 `users`，包含用户 ID、姓名和电子邮件：

```sql
CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    email VARCHAR(50)
);
```

#### 2. **插入数据**

创建表后，可以插入一些数据。例如，向 `users` 表中插入两条记录：

```sql
INSERT INTO users (name, email) VALUES
('Alice', 'alice@example.com'),
('Bob', 'bob@example.com');
```

#### 3. **查询数据**

插入数据后，可以用 `SELECT` 查询表中的数据。下面的命令可以查看 `users` 表中的所有记录：

```sql
SELECT * FROM users;
```

#### 4. **更新数据**

可以修改表中的数据。例如，将 `Alice` 的电子邮件更新为 `alice@newdomain.com`：

```sql
UPDATE users
SET email = 'alice@newdomain.com'
WHERE name = 'Alice';
```

#### 5. **删除数据**

也可以删除不需要的数据。例如，删除用户 `Bob` 的记录：

```sql
DELETE FROM users WHERE name = 'Bob';
```

#### 6. **查看数据库结构**

可以查看当前数据库中有哪些表，以及表的结构：

- **查看所有表**：

  ```sql
  SHOW TABLES;
  ```

- **查看表结构**（比如 `users` 表）：

  ```sql
  DESCRIBE users;
  ```

#### 7. **其他常用 SQL 操作**

还可以尝试一些其他 SQL 操作，比如：

- **计数**：统计表中记录的数量。

  ```sql
  SELECT COUNT(*) FROM users;
  ```

- **条件查询**：查询符合特定条件的记录。

  ```sql
  SELECT * FROM users WHERE email LIKE '%example.com';
  ```

这些基本操作可以帮助你熟悉 MySQL 的基本功能。随时可以试验更多查询和操作！
