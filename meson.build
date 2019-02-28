project('LukeLuaSol', 'cpp', default_options : ['cpp_std=c++14'])

#remove this rather bogus warning
add_project_arguments('-Wno-missing-braces', language: 'cpp')

incDirs = include_directories('.')

# meseon dependency function to find lua is not very consistent accross platforms yet, so
# we need to do a lot of manual lifting for now
foreach name : ['lua', 'lua5.3', 'lua-5.3', 'lua53']
    luaDep = dependency(name, version: '>=5.3', required: false)
    if luaDep.found()
        break
    endif
endforeach

if not luaDep.found()
    error('Lua could not be found!')
endif

incDirs = include_directories('.')

install_headers('LukeLuaSol/LukeLuaSol.hpp', subdir: 'LukeLuaSol')

cc = meson.get_compiler('cpp')
if get_option('buildSubmodules') == false
    stickDep = cc.find_library('Stick')
    lukeDep = cc.find_library('Luke')
    lukeLuaDeps = [stickDep, dependency('threads')]
else
    stickProj = subproject('Stick')
    stickLuaProj = subproject('StickLuaSol')
    lukeProj = subproject('Luke')
    lukeLuaDeps = [stickProj.get_variable('stickDep'), lukeProj.get_variable('lukeDep'),
    stickLuaProj.get_variable('stickLuaDep')]
endif

if host_machine.system() == 'linux'
    lukeLuaDeps += cc.find_library('dl', required : true)
endif

lukeLuaDeps += luaDep

lukeLua = library('LukeLuaSol', 
        'LukeLuaSol/LukeLuaSol.cpp',
        dependencies: lukeLuaDeps, 
        include_directories : incDirs,
        install: true)

lukeLuaDep = declare_dependency(link_with : lukeLua, 
    dependencies: lukeLuaDeps, 
    include_directories: incDirs)

