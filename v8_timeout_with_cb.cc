
#ifndef _WIN32
#include <unistd.h>
#endif
#include <nan.h>

using namespace v8;

NAN_METHOD(Delay)
{

    Nan::HandleScope scope;

    Nan::Maybe<int> maybeNum = Nan::To<int>(info[0]);
    if (maybeNum.IsNothing())
    {
        Nan::ThrowTypeError("Argument must be a number");
        return;
    }
    int num = maybeNum.FromJust();

#ifdef _WIN32
    Sleep(num);
#else
    usleep(num * 1000);
#endif
    Local<Function> callback = info[1].As<Function>();

    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), callback, 0, NULL);
}

NAN_MODULE_INIT(Init)
{
    Nan::Set(target, Nan::New("delay").ToLocalChecked(),
             Nan::GetFunction(Nan::New<FunctionTemplate>(Delay)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init);
