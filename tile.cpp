#include "tile.hpp"


Tile::Tile(double x, double y):x(x),y(y){
    tile.loadFromFile("images/tiles.png");
    tile_image.setTexture(tile);
    left=rand_choice();
    shape_number=rand_int(0,shapes.size());
    tile_image.setTextureRect(sf::IntRect(shape_number,0,18,18));
    //tile_image.setPosition(x,y);
    //printf("shape %d\n",shape_number);
    std::vector<std::pair<int,int>> shape=shapes[shape_number];
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
    shape_number=other.shape_number;
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
double Tile::get_left(){
    double left=3;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j] and j<left) left=j;
        }
    }
    return left;
}
double Tile::get_top(){
    double top=3;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j] and i<top) top=i;
        }
    }
    return top;
}
double Tile::get_bottom(){
    double buttom=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j] and i>buttom) buttom=i;
        }
    }
    return buttom;
}

void Tile::move(Direction dir,short grid[NBHEIGHT][NBWIDTH]){
    //printf("%lf,%lf)\n",x,y);
    Tile tmp(*this);

    if (dir==Direction::Left)tmp.x-=18;
    else if(dir==Direction::Right) tmp.x+=18;
    if(dir==Direction::Left and tmp.is_valide_move(grid)){
        x-=18;
    }
    else if(dir==Direction::Right and tmp.is_valide_move(grid)){
        x+=18;
    }
}
void Tile::shift(){
    if (shape_number == 1)return; 
    //if(get_bottom()==3 or get_right()==3) return;
    if(get_left()==1){
        for(int i=0;i<4;i++){
            for(int j=1;j<4;j++){
                tile_grid[i][j-1]=tile_grid[i][j];
            }
        }
        for(int i=0;i<4;i++){
            tile_grid[i][3]=false;
        }
    }
    else if(get_left()==2){
        for(int i=0;i<4;i++){
            for(int j=2;j<4;j++){
                tile_grid[i][j-2]=tile_grid[i][j];
            }
        }
        for(int i=0;i<4;i++){
            tile_grid[i][2]=false;
            tile_grid[i][3]=false;
        }
    }
}

void Tile::rotate(short grid[NBHEIGHT][NBWIDTH]){
    //puts("rotate");
    if(is_valide_rotate(grid))
    for(int i=0;i<4/2;i++){
        for(int j=i;j<4-i-1;j++){
            bool tmp=tile_grid[i][j];
            tile_grid[i][j] = tile_grid[4 - 1 - j][i];
            tile_grid[4 - 1 - j][i] = tile_grid[4 - 1 - i][4 - 1 - j];
            tile_grid[4 - 1 - i][4 - 1 - j] = tile_grid[j][4 - 1 - i];
            tile_grid[j][4 - 1 - i] = tmp;
        }
    }
    shift();
}
double Tile::get_x(){
    return x;
}
double Tile::get_y(){
    return y;
}

void Tile::gravity(short grid[NBHEIGHT][NBWIDTH],bool &new_tile){
    //printf("y=%lf\n",y);
    if(!check_for_dead_end(grid))
        y+=18;
    else{
        //puts("else");
        int indx=x/18;
        int indy=y/18;
        //printf("(%d,%d)\n",indx,indy);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(tile_grid[i][j]) grid[indy+i][indx+j]=left+1;
            }
        }
        /*for(int i=0;i<NBHEIGHT;i++){
            for(int j=0;j<NBWIDTH;j++){
                printf("%d ",grid[i][j]);
            }
            puts("");
        }*/
        new_tile=true;
    }
}
bool Tile::check_for_dead_end(short grid[NBHEIGHT][NBWIDTH]){
    int indx=x/18;
    int indy=y/18;
    if (indy+get_bottom()== NBHEIGHT-1) return true;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j] and grid[indy+i+1][indx+j])
                return true;
        }
    }
    return false;
}

Tile& Tile::operator=(const Tile &other){
    if(this!=&other){
        x=other.x;
        y=other.y;
        tile.loadFromFile("images/tiles.png");
        tile_image.setTexture(tile);
        left=other.left;
        shape_number=other.shape_number;
        tile_image.setTextureRect(sf::IntRect(left,0,18,18));
        //tile_image.setPosition(x,y);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                tile_grid[i][j]=other.tile_grid[i][j];
            }
        }
    }
    return *this;
}

void Tile::set_position(int indx,int indy){
    x=indx;
    y=indy;
}

bool Tile::is_valide_move(short grid[NBHEIGHT][NBWIDTH]){
    if(x+18*get_left()<0 or x/18+get_right()>=NBWIDTH) return false;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(tile_grid[i][j] and grid[static_cast<int>(y/18+i)][static_cast<int>(x/18+j)]) return false;
        }
    }
    return true;
}

bool Tile::is_valide_rotate(short grid[NBHEIGHT][NBWIDTH]){
    Tile temp(*this);
    for(int i=0;i<4/2;i++){
        for(int j=i;j<4-i-1;j++){
            bool tmp=temp.tile_grid[i][j];
            temp.tile_grid[i][j] = temp.tile_grid[4 - 1 - j][i];
            temp.tile_grid[4 - 1 - j][i] = temp.tile_grid[4 - 1 - i][4 - 1 - j];
            temp.tile_grid[4 - 1 - i][4 - 1 - j] = temp.tile_grid[j][4 - 1 - i];
            temp.tile_grid[j][4 - 1 - i] = tmp;
        }
    }
    temp.shift();
    return temp.is_valide_move(grid);

}