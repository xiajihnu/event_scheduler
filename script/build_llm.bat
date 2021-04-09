cd ..\build
cmake .. -DMODULE:STRING=llm -G "Unix Makefiles"
make
.\test\llm\llm_unit.exe