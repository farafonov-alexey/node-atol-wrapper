{
  "targets": [
    {
       "target_name": "copy_fptr_dll",
       "type":"none",
       "copies":
       [
          {
             'destination': '<(module_root_dir)/build/Release',
             'files': ['<(module_root_dir)/src/fptr10.dll'],
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
      "libraries": [ "<(module_root_dir)/src/fptr10.lib"],
      "dependencies" : [ "copy_fptr_dll" ],
    }
  ]
}
