import base
import os
from ETL.ETLModule import ETLModule
from ETL.ETLRepository import ETLRepository
from detection_algorithm.FraudDetector import FraudDetector
import pandas as pd


if __name__ == "__main__":
    base.generateDatabaseSchema()

    ROOT_DIR = os.getcwd()
    etl = ETLModule()
    etl.storeDataToTable(os.path.join(ROOT_DIR, 'data','train_users.csv'))
    etl.storeDataToTable(os.path.join(ROOT_DIR, 'data','transactions.csv'))
    etl.storeDataToTable(os.path.join(ROOT_DIR, 'data','fx_rates.csv'))
    etl.storeDataToTable(os.path.join(ROOT_DIR, 'data','currency_details.csv'))

    etlRepo = ETLRepository()
    
    # 4. Determine whether a user (uuid) might be fraudulent

    df = pd.read_csv(r"C:\Users\USER\Downloads\Revolut_Fraudster_Postgre\data\train_users.csv")
    uuid=df['ID'].values
    
    fd = FraudDetector()
    g=open(r"Frauds_3.txt","w")
    for uid in uuid:
        action = fd.execute(uid)
        if (action!="SAVE"):
            g.write("User ID "+ str(uid)+" is a suspected fraudster.\n")
            g.flush()
        else:
            continue
        
    g.close()
    


