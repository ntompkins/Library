#ifndef BOX_H
#define BOX_H
class Box {
  
  private:
    double length=0.0,
            depth=0.0,
            width=0.0;
  public:
    Box () {
        double L = length;
        double D = depth;
        double W = width;
        
    }
    Box (double L, double W, double D) {
        setLength(L);
        setWidth(W);
        setDepth(D);
    }
    ~Box () {}
    
    // Get methods
    double getLength() {
        return length;
    }
    double getDepth() {
        return depth;
    }
    double getWidth() {
        return width;
    }
    
    // Set methods
    void setLength(double L=0.0) {
        if (L >= 0) length = L;
        else return;
    }
    void setDepth(double D=0.0) {
        if (D >= 0) depth = D;
        else return;
    }
    void setWidth(double W=0.0) {
        if (W >=0) width = W;
        else return;
    }
    
    // Prototypes
    double calcArea();
    double calcVolume();
};

#endif