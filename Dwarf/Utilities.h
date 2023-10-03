#pragma once

#if DC_DEBUG==2
	#define DC_ERROR(x) std::cout<<x<<std::endl;
	#define DC_LOG(x) std::cout<<x<<std::endl;
#elif DC_DEBUG==1
	#define DC_ERROR(x) std::cout<<x<<std::endl;
	#define DC_LOG(x)
#else
	#define DC_ERROR(x)
	#define DC_LOG(x)
#endif

#ifdef DWARF_MSCPP //microsoft cpp, controls what software to be used
	#ifdef DWARF_LIB
		#define DWARF_API __declspec(dllexport) //have it in main project
	#else
		#define DWARF_API __declspec(dllimport) //outside of main project
	#endif
#else
	#define DWARF_API //else api means nothing, will be reomved
#endif

#define DWARF_APPLICATION_START(ClassName) \
int main() \
{ \
	ClassName::Init(); \
	ClassName::RunInterface(); \
	return(0); \
}
//use line continues onto the next line using that symbol