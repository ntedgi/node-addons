#include <nan.h>

using namespace v8;

NAN_METHOD(Length)
{
  Nan::HandleScope scope;
  Nan::MaybeLocal<String> maybeStr = Nan::To<String>(info[0]);
  int len = 0;
  if (maybeStr.IsEmpty() == false)
  {
    Local<String> str = maybeStr.ToLocalChecked();
    auto isolate = info.GetIsolate();
    len = strlen(*String::Utf8Value(isolate, str));
    printf("length: %d\n", len);
    Local<Number> result = Nan::New<Number>(len);
  }
  info.GetReturnValue().Set(len);
}

NAN_MODULE_INIT(Init)
{
  Nan::Set(target, Nan::New("length").ToLocalChecked(),
           Nan::GetFunction(Nan::New<FunctionTemplate>(Length)).ToLocalChecked());
}

NODE_MODULE(myaddon, Init);
