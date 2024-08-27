cmake_minimum_required (VERSION 3.13)

project(QMLTest VERSION 0.0.1 LANGUAGES C CXX ASM)

find_package(Qul)

add_executable(QMLTest)

set(QUL_FONTS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/fonts,${QUL_FONTS_DIR}")

file(GLOB_RECURSE imgSources "*.png")
if(imgSources)
    qul_add_resource(QMLTest FILES ${imgSources})
endif()

file(GLOB_RECURSE qmlSources "*.qml")
qul_target_qml_sources(QMLTest ${qmlSources})

target_link_libraries(QMLTest Qul::QuickUltralite Qul::QuickUltraliteTimeline Qul::QuickUltraliteControlsStyleDefault)

app_target_setup_os(QMLTest)
app_target_default_main(QMLTest QMLTest)
