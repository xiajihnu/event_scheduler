cd ..\build
cmake .. -DMODULE:STRING=es -G "Unix Makefiles"
make
.\test\es\es_unit.exe