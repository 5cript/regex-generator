include(FetchContent)
FetchContent_Declare(
	nui
	GIT_REPOSITORY https://github.com/NuiCpp/Nui.git
	GIT_TAG        f3e4d65fef3b14b6a9bcf8bc2b57d97946ab3f59    
)
FetchContent_MakeAvailable(nui)