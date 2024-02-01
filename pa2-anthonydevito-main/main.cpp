
#include "functions.h"
#include "Destination.h"
#include "ListMyJoesph.hpp"
#include "VectorMyJoseph.hpp"
#include "TestVectorMyJosephus.cpp"
#include "TestListMyJosephus.cpp"



int main()
{
//(2 pts) Does the processor of the machine that is running the algorithms matter? Will you receive the 
//same timing statistics on every machine? 

   // Yes the processor of the machine does impact timing statistics. Meaning you won't recieve the same timing statistics on every machine.
 
//(5 pts) Which of the two implementations (std::list vs. std::vector) performs best and under what 
// conditions? Does it depend on the input? 

   // The vector preforms best in these circumstances because it allows the user to "instantly" index a value of the vector, making everything about this
   // problem faster with a vector. But typically each are good at different things, vector gives you more speed if you know exactly what you are
   // look for in a preset size. If that's not what you are doing a list preforms better at inserting and deletion with large or unknown amounts of data.
   // So yes, it doesn't matter in the input in this case, vector beats list, my data shows that. I ran all these tests with just barebones code (no prints or whatever)
   // I only have it converted back to how it is now because it's what professor wanted. 
 
//(3 pts) How does the running time dependency on the parameter N compare with the dependency on 
// the parameter M?      
   // In my case, the larger N & M was, the longer the running time was.
   // The running time in this scales lineary - O(N)

// uncomment the one you want to test!

   testVectorMJ();
   //testListMJ();
   

   



   return 0;
}