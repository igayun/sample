#!/bin/sh

printf "#include \"log_decode.h\"\n\n"
printf "logTable_t logTable[] = {\n"

cat src/*.o | perl -pe 's/\n//' | perl -pe 's/logW\(/\nlogW\(/g' | grep ^logW | perl -pe 's/",.*;.*/"/' | perl -pe 's/logW\(//' | sed -e 's/^/    {/' | sed -e 's/$/},/'

printf "};\n"

printf "unsigned int g_logTableNum = sizeof(logTable)/sizeof(logTable[0]);\n"
