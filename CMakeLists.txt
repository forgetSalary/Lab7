cmake_minimum_required(VERSION 3.17)
project(GraphMatrix C)

set(CMAKE_C_STANDARD 99)

#output
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "C:/code/CPrctc/C graphs/cmake-build-debug")

#add_executable(GraphMatrix_C main.c)
add_executable(GraphMatrix_C main.c modules/extern/tools.c modules/extern/tools.h modules/coloring.c modules/coloring.h modules/dfs.c modules/dfs.h modules/lists.c modules/lists.h modules/listsGraph.c modules/listsGraph.h modules/matrix.c modules/matrix.h modules/matrixgraph.c modules/matrixgraph.h modules/bfs.c modules/bfs.h tests.c tests.h modules/extern/al_string.c modules/extern/al_string.h modules/extern/array.h modules/extern/array.c modules/extern/consoleColors.c modules/extern/consoleColors.h modules/vertex.h modules/vertex.c modules/extern/limitedQueue.h modules/extern/limitedQueue.c modules/extern/stretchy_buffers.c modules/extern/stretchy_buffers.h)
