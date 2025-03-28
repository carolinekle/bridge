    if (noFood >= 3) {
        int x = getX();
        int y = getY();
        world[x][y] = nullptr; 
        delete this; 
    }
}