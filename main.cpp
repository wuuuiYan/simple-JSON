#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include <json/json.h>
using namespace yazi::json;

/* Tips
    1) 先按Ctrl + k，再按Ctrl + c，可以注释选中的多行代码
    2) 先按Ctrl + k，再按Ctrl + u，可以取消注释选中的多行代码(Ctrl + k称为先导按键)
    3) 本代码在Windows环境下无法运行，在Linux环境下通过makefile编译后可以运行
*/

int main()
{
    // ifstream fin("./main.json");
    // stringstream ss;
    // ss << fin.rdbuf();
    // const string & data = ss.str();
    // Json v;
    // v.parse(data);
    // std::cout << v.str() << std::endl;
    // return 0;

    Json v1 = true;
    Json v2 = 123;
    Json v3 = 1.23;
    Json v4 = "hello world";
    const string & s = v4;
    std::cout << s << std::endl;
    std::cout << v1.str() << std::endl;
    std::cout << v2.str() << std::endl;
    std::cout << v3.str() << std::endl;
    std::cout << v4.str() << std::endl;

    bool b = v1;
    int i = v2;
    double f = v3;
    const string & s = v4;

    Json null;
    std::cout << null.str() << std::endl;
    return 0;

    // // array value
    // Json arr;
    // arr.append(123);
    // arr.append(1.23);
    // arr.append("hello world");
    // std::cout << arr.str() << std::endl;
    // std::cout << arr[0] << "," << arr[1] << "," << arr[2] << std::endl;
    // return 0;

    // // object value
    // Json obj;
    // obj["name"] = "jun";
    // obj["age"] = 18;
    // obj["arr"] = arr;
    // std::cout << obj.str() << std::endl;
    // obj.clear();
    // return 0;
}
