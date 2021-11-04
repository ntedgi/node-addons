{
  "targets": [
    {
      "target_name": "myaddon",
      "sources": [ "fn_with_return_fucntion.cc" ],
      "include_dirs": [  "<!(node -e \"require('nan')\")"]
    }
  ]
}
