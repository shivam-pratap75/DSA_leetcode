/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */

 let check=function(image,sr,sc,originalColor,color,visited){

         if(sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length){
    return ;
}
         if (visited.has(`${sr},${sc}`) || image[sr][sc] !== originalColor) {
        return;
    }
     visited.add(`${sr},${sc}`);
    image[sr][sc] = color;
         check(image,sr-1,sc,originalColor,color,visited);
            check(image,sr,sc-1,originalColor,color,visited);
            check(image,sr+1,sc,originalColor,color,visited);
            check(image,sr,sc+1,originalColor,color,visited);

            return image;
          

 }

var floodFill = function(image, sr, sc, color) {
    const originalColor = image[sr][sc];
    if (originalColor === color) return image; 
    
    let visited = new Set();
    check(image, sr, sc, originalColor, color, visited);
    return image;
};