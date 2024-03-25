#include "tile.hpp"


Tile::Tile(double x, double y):x(x),y(y){
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=rand_choice();
    tile_image.setTextureRect(sf::IntRect(left,0,18,18));
    //tile_image.setPosition(x,y);
    int rand_number=rand_int(0,shapes.size());
    printf("shape %d\n",rand_number);
    std::vector<std::pair<int,int>> shape=shapes[rand_number];
    for(auto it=shape.begin();it!=shape.end();it++){
        tile_grid[it->first][it->second]=true;
    }
}

Tile::Tile(const Tile &other){
    x=other.x;
    y=other.y;
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=other.left;
    tile_image.setTextureRect(sf::IntRect(left,0,18,18));
    //tile_image.setPosition(x,y);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tile_grid[i][j]=other.tile_grid[i][j];
        }
    }

}
void Tile::draw(sf::RenderWindow &window){
    double posx=x,posy=y;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j]){
                tile_image.setPosition(posx,posy);
                window.draw(tile_image);
            }
            posx+=18;
        }
        posx=x;
        posy+=18;
    }
    //window.draw(tile_image);
}


int rand_choice(){
    srand(time(0));
    return rand()%8*18;
}

double Tile::get_right(){
    double right=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j] and j>right) right=j;
        }
    }
    return right;
}

void Tile::move(Direction dir){
    //printf("%lf,%lf)\n",x,y);
    if(dir==Direction::Left){
        if(x>=18) x-=18;
    }
    else if(dir==Direction::Right){
        if(x/18+get_right()+1<NBWIDTH) x+=18;
    }
}

void Tile::rotate(){
    
}