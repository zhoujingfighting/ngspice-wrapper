{
  "targets": [
    {
      "target_name": "hello",
      "cflags!": ["-ferror-limit=500" , "-fno-exceptions" ],
      "cflags_cc!": ["-ferror-limit=500" , "-fno-exceptions"],
      "sources": [ "hello.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'conditions': [
        ['OS=="mac"', {
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
            'OTHER_CFLAGS': [
                '-ferror-limit=0'
            ]
          }
        }]
      ],
    "libraries":["libngspice.0.dylib"],
    "link_settings": {
        "library_dirs": [
          "../35/lib",
          ]
      }
    }
  ]
}