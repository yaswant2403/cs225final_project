set(src_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add overall src library.
file(GLOB_RECURSE src_sources CONFIGURE_DEPENDS ${src_dir}/*.cpp)
add_library(src ${src_sources})
target_include_directories(src PUBLIC ${src_dir})
#Uncomment if we end up using cs 225 lib directory 
#target_link_libraries(src PRIVATE libs)