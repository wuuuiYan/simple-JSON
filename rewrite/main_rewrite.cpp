#include <iostream>
#include <fstream>
#include <sstream>
#include "json_rewrite/json_rewrite.h" //包含不在当前目录下的头文件时，要使用相对路径或绝对路径
// 包含每一个头文件都要思路清晰，不要一股脑都包含进来，否则会造成循环引用
using namespace std;
using namespace yazi_rewrite::json_rewrite;

/* Tips:
    1) 视频版本代码支持在VSCode下编译运行，编译连接命令如下：
        g++ main_rewrite.cpp json_rewrite/json_rewrite.cpp json_rewrite/json_rewrite.h json_rewrite/parser_rewrite.h json_rewrite/parser_rewrite.cpp -o main
    2) 为了防止类名称空间冲突，将类改名为JsonRe，文件名添加后缀_rewrite
*/

int main()
{
    cout << "JsonRe main.cpp" << endl;

    // Json v1;
    // Json v2 = true;
    // Json v3 = 123;
    // Json v4 = 1.23;
    // Json v5 = "Hello World!";

    // bool b = v2;
    // int i = v3;
    // double f = v4;
    // const string &s = v5;

    // JsonRe arr;
    // arr[0] = true; 
    // arr[1] = 123;
    // 先调用转换构造函数将左边的内置类型转化为Json类型
    // 再调用下标访问运算符返回该位置的对象，最后调用默认的赋值运算符进行赋值
    // arr.append(1.23);
    // arr.append("Hello World!");
    // cout << arr.str() << endl;
    // for (auto it = arr.begin(); it != arr.end(); it++)
    // {
    //     cout << (*it).str() << endl;
    // }

    // cout << arr.has(0) << endl;
    // arr.remove(0);
    // cout << arr.str() << endl;

    // bool b = arr[0];
    // int i = arr[1];
    // double f = arr[2];
    // const string &s = arr[3];

    // JsonRe obj;
    // obj["bool"] = true;
    // obj["int"] = 123;
    // obj["double"] = 1.23;
    // obj["str"] = "Hello World!";
    // cout << obj.str() << endl;
    // cout << obj.has("bool") << endl;
    // obj.remove("int");
    // cout << obj.str() << endl;
    // obj.clear();

    // const string & str = "{\"a\": 1, \"b\": 2, \"c\": 3}";
    // JsonRe v;
    // v.parse(str);
    // cout << v.str() << endl;

    // 注意对字符串的理解：两边的双引号只是字符串的格式，字符串的第一个字符可不是前双引号
    // 如果想要让字符串的内容也是个字符串，需要使用转移字符，比如 str = "\"hello world\""
    // const string & str = "[\"a\", 1, 1.23, true, false, null]"; 
    // JsonRe v;
    // v.parse(str);
    // cout << v.str() << endl;

    ifstream fin("../test.json");
    stringstream ss;
    ss << fin.rdbuf();
    const string & str = ss.str();

    JsonRe v;
    v.parse(str);
    cout << v.str() << endl; 
    // 由于字段类型为json_object的字段内容使用map容器进行存储，所以最后输出的顺序可能和原文件的顺序不一致，这属于正常状况

    // cout << "--------------" << endl;

    // bool isLogin = v["data"]["isLogin"];
    // cout << isLogin << endl;

    // int current_level = v["data"]["level_info"]["current_level"];
    // cout << current_level << endl;

    return 0;
}