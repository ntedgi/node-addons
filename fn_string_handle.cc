#include <nan.h>

using namespace v8;

NAN_METHOD(Print)
{
  Nan::MaybeLocal<String> maybeNum = Nan::To<String>(info[0]);
  if (maybeNum.IsEmpty() == false)
  {
    Local<String> str = maybeNum.ToLocalChecked();
    auto isolate = info.GetIsolate();
    printf("%s\n", *String::Utf8Value(isolate, str));
  }
}

NAN_MODULE_INIT(Init)
{
  Nan::Set(target, Nan::New("print").ToLocalChecked(),
           Nan::GetFunction(Nan::New<FunctionTemplate>(Print)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init);
