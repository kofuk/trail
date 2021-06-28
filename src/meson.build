srcs = [
  'main.cc',
  'parser.cc',
  'tokenizer.cc',
  'token.cc',
  'variable.cc',
]

exe = executable(
  meson.project_name(),
  srcs)

run_target(
  'run',
  depends : exe,
  command : [exe])
