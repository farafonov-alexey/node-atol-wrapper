{
  "variables": {
    'arch': '<(target_arch)'
  },
  "targets": [
    {
       "target_name": "copy_fptr_libs",
       "type":"none",
       "copies":
       [
          {
             'destination': '<(PRODUCT_DIR)',
             'conditions':[
               ["OS=='win'", {
                 'conditions':[
                   ["arch=='ia32'", {
                     'files': [
                       '<(module_root_dir)/src/win-x86/fptr10.dll',
                       '<(module_root_dir)/src/win-x86/msvcp140.dll',
                       '<(module_root_dir)/src/win-x86/fptr10.lib',
                     ],
                   }],
                   ["arch=='x64'", {
                     'files': [
                       '<(module_root_dir)/src/win-x64/fptr10.dll',
                       '<(module_root_dir)/src/win-x64/msvcp140.dll',
                       '<(module_root_dir)/src/win-x64/fptr10.lib',
                     ],
                   }]
                 ]
               }],
               ["OS=='linux'",{
                 'conditions':[
                    ["arch=='ia32'", {
                      'files': [
                        '<(module_root_dir)/src/linux-x86/libfptr10.so',
                        '<(module_root_dir)/src/linux-x86/libudev.so.0',
                        '<(module_root_dir)/src/linux-x86/libusb-1.0.so.0',
                      ],
                    }],
                    ["arch=='x64'", {
                      'files': [
                        '<(module_root_dir)/src/linux-x64/libfptr10.so',
                        '<(module_root_dir)/src/linux-x64/libudev.so.0',
                        '<(module_root_dir)/src/linux-x64/libusb-1.0.so.0',
                      ],
                    }],
                    ["arch=='arm'", {
                      'files': [
                        '<(module_root_dir)/src/linux-armhf/libfptr10.so',
                        '<(module_root_dir)/src/linux-armhf/libudev.so.1',
                        '<(module_root_dir)/src/linux-armhf/libusb-1.0.so.0',
                      ],
                    }],
                    ["arch=='arm64'", {
                      'files': [
                        '<(module_root_dir)/src/linux-arm64/libfptr10.so',
                        '<(module_root_dir)/src/linux-arm64/libudev.so.1',
                        '<(module_root_dir)/src/linux-arm64/libusb-1.0.so.0',
                      ],
                    }]
                 ]
               }],
               ["OS=='mac'", {
                 'files': [
                   "<(module_root_dir)/src/macos-x86_64/fptr10.framework"
                 ]
               }],
             ],
          }
       ]
    },
    {
      "target_name": "node_atol_wrapper",
      "include_dirs" : [
        "src",
        "<!(node -e \"require('nan')\")"
      ],
      "sources": [
        "src/index.cc",
        "src/fptr10.cc",
        "src/utils.cc",
        "src/json_worker.cc"
      ],
      "conditions":[
      	["OS=='linux'", {
      	  "link_settings": {
      	    "libraries": ["-lfptr10", ],
      	    "ldflags": [
      	       "-L<(module_root_dir)/build/Release",
      	       "-Wl,-rpath,<(module_root_dir)/build/Release"
      	    ],
      	  },
      	}],
        ["OS=='win'", {
      	  "link_settings": {
      	    "libraries": ["<(module_root_dir)/build/Release/fptr10.lib", ],
      	  },
      	}],
      	["OS=='mac'", {
          "link_settings": {
            "libraries": [
              "<(module_root_dir)/build/Release/fptr10.framework/Versions/A/fptr10",
              "-Wl,-rpath,@loader_path",
            ],
          },
        }]
      ],
      "dependencies" : [ "copy_fptr_libs" ],
    }
  ]
}
