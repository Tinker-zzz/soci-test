#include "soci.h"
#include "mysql/soci-mysql.h"
#include "sqlite3/soci-sqlite3.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <exception>

using namespace std;
using namespace soci;

int main() {
        session sqlite(sqlite3, "t.db");
        sqlite <<
                  "create table if not exists test ("
                  "     id interger,"
                  "     name varchar(100)"
                  ")";

        sqlite << "insert into test(id, name) values (7, \'jin\')";

        rowid rid(sqlite);

        sqlite << "select oid from test where id = 7", into(rid);
        int id;
        string name;
        sqlite << "select id,name from test where oid = :rid",into(id),into(name), use(rid);
        cout << "id=" <<id <<endl;
        cout << "name=" << name << endl;
    try {
        session sql(mysql, "service=student user=root password=72");
        int count ;
        sql<< "select count(*) from student_info", into(count);
        cout<<"count="<<count<<endl;
    } catch (exception const &e) {
        cerr<<"Error:" <<e.what()<<endl;
    }




}
