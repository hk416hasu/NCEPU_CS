import duckdb

# create a connection to a file called 'file.db'
con = duckdb.connect("demo.db")
# create a table and load data into it
con.sql("CREATE TABLE if not exists test (i INTEGER)")
con.sql("INSERT INTO test VALUES (42)")
# query the table
# con.table("test").show()
con.sql("select count(*) as count\
      from test t1 \
      ").show()
# explicitly close the connection
con.close()
# Note: connections also closed implicitly when they go out of scope
