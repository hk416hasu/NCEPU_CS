### Goooood aspects
0. We separate the big software to some small modules
1. Each module has its own database
    - the table is inside each module, so it can be changed easily,
    - or the tables will be another "API" and causing depandency hells
    - datas will be exchanged in communicating of modules by calling APIs, as json files or something else
2. We use html-css-javascript as our front-end and C/S mode, which is universal and highly compatiable
3. We have a remote, shared and same mysql server, it's important to ensure the consistency of developing env
4. We choose to use Mysql, which is popular and owns large users, so that u can find the solution easily on the Internet
    - it owns C/C++ api too! We needn't to develop ourselves, happy~
5. We use node.js as the middleware
    - high performance and easy(?) to develop
    - fruitful libs: native mysql module and native ReExp support for input check
6. (I wish) We use git/GitHub to cooperate
    - As a Version Control tool, git can help us to avoid many problems
        - why the program can work just 10 mins ago, but NOT now? 
    - Github makes the leader merge codes from each teamers more conveniently, instead of manually
7. We choose the mysql Parameterized-Queries to prevent SQL-Injection-Attacks
8. Import necessary book info from `http://opac.nlc.cn`
9. We will use `mysqldump` and `bash` to automatically backup databases in mysql (backup: `tldr mysqldump`)
    - it will gen a .sql file, which can be imported into mysql (restore: `tldr mysql`)
10. The front-end will POST the hash value of users'plain-passwd
    - ~~(advanced) a dynamic hash passed is better, but more challenging~~
    - We use https😎




### Need more concern
1. The mysql server is remote, so the unit test maybe a little confused and challenging
2. We haven't determine 
    - the depandency of software, like version of mysql C api, mysql, nodejs, npm, mysql2 module, express etc.
    - the C/C++ version/standard, C++11, or C++17 or C++23?
        - no need to concern about OS (i think)
    - the compiler and its version
    - the APIs design of modules
3. How to prepare for the future?
    - No prepare: KISS + YAGNI
4. i want to employ the Scrum?
5. (advanced) Exponential Backoff Strategy for Network Timeouts
6. We will communicate by static files, how can we resolve .json in C/C++?


#### What should we do next?
1. the APIs of each modules should be designed and discussed, at least one time
    - design indenpendly, and review together
2. Our architecture is good enough, or not? Try to solve your teamers question!
