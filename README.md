# Spot-Information-Manager
desc: A Spot Information Manager for Data Structure class.



## Compiler

- Visual Studio 2019
- Windows Development Kit 10



## Design

- use C++ as the main design language

- use MFC as the visible design (Only for Windows)
- use Visual Studio as the main design IDE



## Data Structure

- use some STL to make things easier

- Graph APIs are in "UnOrderGraph.h"

- Node Info has

  - index ------- integer
  - name ------- CString
  - desc -------- CString

  

## Problems when develop

- MST(Minimum Spanning Tree)'s algorithm Prim

  in fact I use Kruskal for the most time so it's a little of hard for me to write a Prim

- The Unicode problem, at first it can't display Chinese, just to change the Unicode settings for the project

- C++ project's extern variable, I still can't use extern variable in a normally way, which makes me have to initial different variable in different class even though they have same content.(see the file "GraphInfoForApp.h")

- To create complete status code system and give different ways to solve them is really difficult, I just ignore the failing code in my Graph APIs.