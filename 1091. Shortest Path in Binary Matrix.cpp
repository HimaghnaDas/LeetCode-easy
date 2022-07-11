struct Point{
    int x ;    // x cordinate 
    int y ;    // y cordinate
    int cnt ;  // cnt is the number of cells included in the path at every cordinate x and y 
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        // Since we can move in 8 directions
        int dx[8] = {1,1,1,-1,-1,-1,0,0};
        int dy[8] = {1,0,-1,1,-1,0,1,-1};
        
        // Base case : Starting cell is blocked we can't move forward 
        if( grid[0][0] == 1 ) return -1 ;
        
        int rows = grid.size() ;
        int columns = grid[0].size() ;
        
        queue<Point> q ;  
        q.push({0,0,1}) ;   // We are staring from (0,0) cordinate and the cnt value is 1 
        grid[0][0] = -1 ;    // Mark the visited cell as -1 
        
        while( !q.empty() ){
            
            Point p = q.front() ;  // BFS Traversal 
            q.pop() ;
            
            if( p.x == rows-1 && p.y == columns-1 )  // if we have reached the last right corner 
                return p.cnt ;
            
            // Traverse in all 8 directions 
            for( int i=0 ; i<8 ; i++ ){
                
                int x = p.x + dx[i] ;     // Iterate in every direction in one by one
                int y = p.y + dy[i] ;
                
                // Always check the boundary limits 
                if( x>=0 && y>=0 && x<rows && y<columns && grid[x][y]==0 ){
                    q.push({ x, y, p.cnt+1 });     // Since you are able to visit the next cell add it into ur path i.e cnt+1 
                    grid[x][y] = -1 ;      // Mark this cell as visited 
                }
            }
        }  
		// if we are not able to access any path 
        return -1 ;
    }
};