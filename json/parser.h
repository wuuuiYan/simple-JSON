#pragma once

#include <json/json.h>

namespace yazi {
namespace json {

class Parser
{
public:
    Parser(); //构造函数
    ~Parser(); //析构函数

    // 加载待解析的字符串
    void load(const string & str);

    // 返回解析完毕的Json对象
    Json parse();

private:
    // 忽略空白字符
    void skip_white_space();
    // 获取下一个字符
    char get_next_token();

    // 分别按照字段类型进行解析的私有成员函数，只会被成员函数parse()调用，所以可以设为private
    Json parse_null();
    Json parse_bool();
    Json parse_number();
    // NOTE：这个解析函数的返回值与其他解析函数不同，因为它的功能还要在map中解析key时用到
    string parse_string();
    Json parse_array();
    Json parse_object();

    bool in_range(int x, int lower, int upper)
    {
        return (x >= lower && x <= upper);
    }

private:
    string m_str; //先把待处理的文件中的内容全部看成字符串，再从字符串中具体分离不同字段类型
    size_t m_idx; //当前解析的字符位置/下标索引
};

}}
