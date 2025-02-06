char flight[20];
        int t;
        char countery[20];
        if(sscanf(token,"['%[^']',%d,'%[^']",flight,t,countery)==3){
            printf("%s %d %s\n",flight,t,countery);
        }