class Spreadsheet {
public:
     vector<vector<int>> mat;
    Spreadsheet(int rows) {
         mat = vector<vector<int>>(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0]-'A';
        string num="";
        
        for(int i=1;i<cell.size();i++){
            num+=cell[i];
        }
        int row = stoi(num);
        mat[row-1][col]=value;
    }
    
    void resetCell(string cell) {
        int col = cell[0]-'A';
        string num="";
        
        for(int i=1;i<cell.size();i++){
            num+=cell[i];
        }
        int row = stoi(num);
        mat[row-1][col]=0;
    }
    
    int getValue(string formula) {
        int a,b;
        int i=1;
        if(isdigit(formula[i])){
            string num1 = "";
            while(formula[i]!='+'){
                num1 += formula[i];
                i++;
            }
            a = stoi(num1);
        }else{
           int col = formula[i]-'A';
            string num1="";
            i++;
            while(formula[i]!='+'){
                num1 += formula[i];
                i++;
            }
            int row = stoi(num1); 
            a = mat[row-1][col];
        }
        i++;
        if(isdigit(formula[i])){
            string num1 = "";
            while(i<formula.size()){
                num1 += formula[i];
                i++;
            }
            b = stoi(num1);
        }else{
           int col = formula[i]-'A';
           i++;
            string num1="";
            while(i<formula.size()){
                num1 += formula[i];
                i++;
            }
            int row = stoi(num1); 
            b = mat[row-1][col];
        }
        return a+b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */