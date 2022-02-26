#include <napi.h>
//相对路径
#include "sharedspice.h"
using namespace std;
// Napi::String Method(const Napi::CallbackInfo &info)
// {
//     Napi::Env env = info.Env();
//     char *efe = ".params efef=1232 \n end";
//     int b = ngSpice_Circ(&efe);
//     std::printf("fefe");
//     return Napi::String::New(env, b);
// }
Napi::Value Add(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
                 //接收第一个参数
    std::printf("1231232fdfd\n");
    double arg0 = info[0].As<Napi::Number>().DoubleValue();
    //接受第二个参数
    double arg1 = info[1].As<Napi::Number>().DoubleValue();
    Napi::Number num = Napi::Number::New(env, arg0 + arg1);
    return num;
}
Napi::Object Init(Napi::Env env, Napi::Object exports)
{
    // exports.Set(Napi::String::New(env, 'test'),
    //             Napi::Function::New(env, Method));
    //这里有多少种方法就需要暴露出来！！前面一个是函数名，后面一个是具体的方法！！
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
    return exports;
}
//表示指针的意思
/**
 *
 * env 是什么意思，C++需要写分号
 *
 */

//这里是具体暴露给JS的模块的名字
NODE_API_MODULE(hello, Init)