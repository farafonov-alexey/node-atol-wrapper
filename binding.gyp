{
  "variables": {
    'arch': '<!(node -e "console.log(process.arch)")'
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
                       '<(module_root_dir)/src/win-x86/fptr10.lib',
                     ],
                   }],
                   ["arch=='x64'", {
                     'files': [
                       '<(module_root_dir)/src/win-x64/fptr10.dll',
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
                    }]
                 ]
               }],
               ["OS=='darwin'", {
                  'files': [
                    '<(module_root_dir)/src/linux-x64/libfptr10.so',
                  ],
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
        "src/utils.cc"
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
      	["OS=='darwin'", {
          "sources!": [
            "src/index.cc",
            "src/fptr10.cc",
            "src/utils.cc"
          ],
          "dependencies!": [
            "copy_fptr_libs"
          ]
        }]
      ],
      "dependencies" : [ "copy_fptr_libs" ],
    }
  ]
}
