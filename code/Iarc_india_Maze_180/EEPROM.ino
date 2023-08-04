void EEPROM_Clear(){
  for ( int i = 0 ; i < 30 ; i++ ){
      EEPROM.write(i, 0);    
  }
  
}


void EEPROM_Write(){
    for(int j = 0; j < 30; j++){
        EEPROM.write(j, path[j]);

    }
    for(int j = 0; j < 30; j++){
        Serial.print(j, path[j]);

    }
}

void EEPROM_Read(){
  
  for(int j = 0; j < 30; j++){
        path[j]=EEPROM.read(j);

    }
    
}
