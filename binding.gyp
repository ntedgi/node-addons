{
  "targets": [
    {
      "target_name": "myaddon",
      "sources": [ "v8_timeout_with_cb.cc" ],
      "include_dirs": [  "<!(node -e \"require('nan')\")"]
    }
  ]
}
