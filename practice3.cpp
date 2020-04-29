
#include <vector>
#include <iostream>
#include <string>

using namespace std;


template<class T>
void
_print(T arg) {
    cout << arg << " ";
}

template<class... Args>
void
log(Args... args) {
    int arr[] = { (_print(args), 0)... };
    cout << endl;
}

void
ensure(bool condition, const string &message) {
    // 在条件不成立的时候, 输出 message
    if (not condition) {
        log("*** 测试失败: ", message);
    } else {
        log("||| 测试成功");
    }
}



// 作业 1
//
string nChar(int n) {
    char fillchar = '0';
    string r = "";
    int i = 0;
    while(i < n) {
        r += fillchar;
        i += 1;
    }
    return r;
}


string
zfill(int n, int width) {
    // 把 n 的位数变成 width 这么长，并在右对齐，不足部分用 0 补足并返回
    // 具体请看测试
    // 提示:
    // 计算 n 的长度, 随后生成一串指定长度的 0, 使两者组合后长度为 width

    // 本题需要求 string 的长度，例子如下
    // log("字符串长度", string("gua").length());
    // 输出结果是 “字符串长度 3”
    
    string res = to_string(n);
    size_t i = res.length();
    string s = "";
    if (i < width) {
        int n = width - i;
        s = nChar(n);
    }
    res = s + res;
    return res;
}

// 测试函数
void
testZfill() {
    ensure(zfill(1, 4) == "0001", "zfill 测试 1");
    ensure(zfill(23, 4) == "0023", "zfill 测试 2");
    ensure(zfill(12345, 4) == "12345", "zfill 测试 3");
    ensure(zfill(169, 5) == "00169", "zfill 测试 4");
}


string
nfillChar(int n, char fillchar='0') {
    string r = "";
    int i = 0;
    while(i < n) {
        r += fillchar;
        i += 1;
    }
    return r;
}


// 作业 2
//
string
rjust(const string &s, int width, char fillchar=' ') {
    // 如果 s 长度小于 width, 则在开头用 fillchar 填充并返回

    // 返回 string 类型

    // 提示:
    // 类似于作业 1, 但有几个区别
    // 一是不需要先用 string() 转换类型
    // 二是填充的字符不是 0 而是可以自行定义

    // 分步提示：
    // 1. 计算需要用 fillchar 生成的字符串长度
    // 2. 使用作业 1 中的辅助函数 nChar, 修改它以便符合本题的使用
    // 3. 调用修改后的 nChar 生成填充用的字符串
    // 4. 拼接并返回结果
    string res = s;
    size_t i = s.length();
    string fill = "";
    if (i < width) {
        int n = width - i;
        fill = nfillChar(n, fillchar);
    }
    res = fill + res;
    return res;
    
}

// 测试函数
void
testRjust() {
    ensure(rjust("gua", 5) == "  gua", "rjust 测试 1");
    ensure(rjust("guagua", 5) == "guagua", "rjust 测试 2");
    ensure(rjust("gua", 5, '*') == "**gua", "rjust 测试 3");
}


// 作业 3
//
string ljust(string s, int width, char fillchar=' ') {
    // s 是 string
    // width 是 整数
    // fillchar 是 长度为 1 的字符串, 默认为空格 ' '

    // 如果 s 长度小于 width, 则在末尾用 fillchar 填充并返回
    // 否则, 原样返回, 不做额外处理

    // 返回 string 类型
    string res = s;
    size_t i = s.length();
    string fill = "";
    if (i < width) {
        int n = width - i;
        fill = nfillChar(n, fillchar);
    }
    res = res + fill;
    return res;
    

}

// 测试函数
void
testLjust() {
    ensure(ljust("gua", 5) == "gua  ", "ljust 测试 1");
    ensure(ljust("guagua", 5) == "guagua", "ljust 测试 2");
    ensure(ljust("gua", 5, '*') == "gua**", "ljust 测试 3");
}


// 作业 4
//
string
center(const string &s, int width, char fillchar=' ') {
    // 如果 s 长度小于 width, 则在两边用 fillchar 填充并返回
    // 如果 s 长度和 width 互为奇偶, 则无法平均分配两边的 fillchar
    //     这种情况下, 让左边的 fillchar 数量小于右边

    // 返回 string 类型

    // 提示:
    // 需要计算 s 左右两侧字符串的长度后, 分别生成左右填充字符串, 并最终把三者按顺序拼接

    // 实现步骤
    // 1. 计算左右填充字符串的总长度
    // 2. 计算左右填充字符串的长度，注意要是整数
    //      C++ 中 5/2 结果是 2
    // 3. 生成左右两个填充字符串
    // 4. 拼接字符串, 并返回结果
    
    string res = s;
    size_t i = s.length();
    string lFill = "";
    string rFill = "";
    if (i < width) {
        int n = width - i;
        int m = n / 2;
        if (n % 2 == 0) {
            lFill = nfillChar(m, fillchar);
            rFill = nfillChar(m, fillchar);
        } else {
            lFill = nfillChar(m, fillchar);
            rFill = nfillChar(m + 1, fillchar);
        }
    }
    res = lFill + res + rFill;
    return res;
}

// 测试函数
void
testCenter() {
    ensure(center("gua", 5) == " gua ", "center 测试 1");
    ensure(center("gua", 5, '*') == "*gua*", "center 测试 2");
    ensure(center("gw", 5) == " gw  ", "center 测试 3");
    ensure(center("gua", 6) == " gua  ", "center 测试 4");
}


// 作业 5
//
bool
isSpace(const string &s) {
    // 检查 s 中是否只包含空格

    // 返回 布尔值
    // 如果 s 中包含的只有空格则返回 true
    // 否则返回 false

    // 提示:
    // 遍历 s 中的所有字符, 其中如果包含非空格字符, 返回 false, 否则返回 true

    // 实现步骤
    // 1. 如果是一个空字符串返回 false
    // 2. 遍历 s 中的每个字符
    // 3. 如果字符不是空格, 返回 false
    // 4. 在循环结束后, 返回 true
    size_t i = 0;
    if (s.size() < 1) {
        return false;
    }
    
    while (i < s.size()) {
        char n = s[i];
        if (n != ' ') {
            return false;
        }
        i += 1;
    }
    return true;
}

// 测试函数
void
testIsSpace() {
    ensure(isSpace(" "), "isSpace 测试 1");
    ensure(isSpace("   "), "isSpace 测试 2");
    // C++ 中 not 可以替代 !
    // 同理还有 and 替代 && 和 or 替代 ||
    ensure(not isSpace(""), "isSpace 测试 3");
    ensure(not isSpace("gua"), "isSpace 测试 4");
    ensure(not isSpace("  gua"), "isSpace 测试 5");
}


int
find(string &s, char n) {
    size_t i = 0;
    int index = -1;
    while(i < s.size()) {
        char a = s[i];
        if (a == n) {
            index = i;
            break;
        }
        i += 1;
    }
    return index;
}

// 作业 6
//
bool
isDigit(const string &s) {
    // 检查 s 中是否只包含数字
    // 返回: 布尔值

    // 提示:
    // 类似于作业 5, 判断的条件从空格变为了数字

    // 实现步骤
    // 1. 复制 isSpace 函数中的代码
    // 2. 将判断字符是否为空格的部分改为判断是否为数字
    //     通过判断字符是否在字符串 "0123456789" 中, 来判断其是否为数字
    if (s.size() < 1) {
        return false;
    }
    
    string number = "0123456789";
    size_t i = 0;
    while (i < s.size()) {
        char n = s[i];
        int index = find(number, n);
        if (index == -1) {
            return false;
        }
        i += 1;
    }
    return true;
    
    
}

// 测试函数
void
testIsDigit() {
    ensure(isDigit("123"), "is_digit 测试 1");
    ensure(isDigit("0"), "is_digit 测试 2");
    ensure(not isDigit("  "), "is_digit 测试 3");
    ensure(not isDigit("1.1"), "is_digit 测试 4");
    ensure(not isDigit("gua"), "is_digit 测试 5");
    ensure(not isDigit(""), "is_digit 测试 6");
}


// 作业 7
//
string
stripLeft(const string &s) {
    // 返回一个「删除了字符串开始的所有空格」的字符串

    // 返回 string

    // 实现步骤
    // 从左侧遍历字符串, 记录第一个非空格字符的位置, 并由此切割字符串
    // 1. 使用作业 5 的 isSpace 函数来判断 s 是否只包含空格，
    //    如果 s 只包含空格，返回空字符串
    // 2. 遍历字符串找到不是空格的字符的下标
    // 3. 切片并返回
    //      string 的切片方法如下
    //             0123456789
    // string s = "kuaibiancheng";
    // string s1 = s.substr(2, 5);
    // 结果是 aibia
    // 第一个参数表示开始的下标，第二个参数表示切片的个数
    if (s.size() < 1) {
        return s;
    }
    
    size_t i = 0;
    string res = "";
    int index = 0;
    while (i < s.size()) {
        char n = s[i];
        if (n == ' ') {
            index += 1; 
        } else {
            break;
        }
        i += 1;
    }
    res = s.substr(index, s.size());
    return res;

}

// 测试函数
void
testStripLeft() {
    ensure(stripLeft("  gua") == "gua", "stripLeft 测试 1");
    ensure(stripLeft(" gua  ") == "gua  ", "stripLeft 测试 2");
    ensure(stripLeft("") == "", "stripLeft 测试 3");
    ensure(stripLeft("    ") == "", "stripLeft 测试 4");
}


// 作业 8
//
string
stripRight(const string &s) {
    // 返回一个「删除了字符串末尾的所有空格」的字符串

    // 提示:
    // 类似于作业 7
    // 区别在于这次需要从右至左遍历字符串

    // 实现步骤
    // 1. 创建一个循环, 从右到左遍历字符串
    //     从右到左遍历的方式是让数字从 n 到 0
    // 2. 遍历字符串找到不是空格的字符的下标
    // 3. 切片并返回
    if (s.size() < 1) {
        return s;
    }
    
    size_t i = s.size() - 1;
    string res = "";
    int index = s.size() ;
    while (i >= 0) {
        char n = s[i];
        if (n == ' ') {
            index -= 1; 
        } else {
            break;
        }
        i -= 1;
    }
    res = s.substr(0, index);
    return res;
}

// 测试函数
void
testStripRight() {
    ensure(stripRight("gua") == "gua", "stripRight 测试 1");
    ensure(stripRight(" gua  ") == " gua", "stripRight 测试 2");
    ensure(stripRight("") == "", "stripRight 测试 3");
    ensure(stripRight("    ") == "", "stripRight 测试 4");
}


// 作业 9
//
string
strip(const string &s) {
    // 返回一个「删除了字符串首尾的所有空格」的字符串

    // 返回 string

    // 提示:
    // 依次调用作业 7 和作业 8 中的函数即可

    // 分布提示:
    // 1. 调用 stripLeft
    // 2. 对上一步的结果继续调用 stripRight
    // 3. 返回结果
    if (s.size() < 1) {
        return s;
    }
    
    string res = stripRight(s);
    res = stripLeft(res);
    return res;
}

// 测试函数
void
testStrip() {
    ensure(strip("  gua") == "gua", "strip 测试 1");
    ensure(strip(" gua  ") == "gua", "strip 测试 2");
    ensure(strip("") == "", "strip 测试 3");
    ensure(strip("    ") == "", "strip 测试 4");
}


// 作业 10
//
string
replace(const string &s, const string &old_str, const string &new_str) {
    // 返回一个「将 s 中的 old_str 字符串替换为 new_str 字符串」的字符串
    // 假设 old 存在并且只出现一次

    // 返回 string

    // 提示:
    // 找到指定旧字符串的起始下标, 将其前后字符串与新字符串进行拼接

    // 实现步骤
    // 1. 找到 old_str 的下标
    // 2. 把 s 切成 2 个不包含 old_str 的字符串
    // 3. 拼接并返回结果
    int index = -1;
    size_t i = 0;
    string res = "";
    int l = old_str.size();
    while (i < (s.size() - l)) {
        string n = s.substr(i, i + l);
        log(n);
    }
    return res;
    
}

// 测试函数
void
testReplace() {
    ensure(replace("guagua", "ag", "l") == "gulua", "replace 测试 1");
    ensure(replace("g  ", "  ", "a") == "ga", "replace 测试 2");
    ensure(replace("l", "l", "") == "", "replace 测试 3");
}


void
test() {
    testZfill();
    testRjust();
    testLjust();
    testCenter();
    testIsSpace();
    testIsDigit();
    testStripLeft();
    testStripRight();
    testStrip();
}

int
main(int argc, const char *argv[]) {
    test();

    return 0;
}