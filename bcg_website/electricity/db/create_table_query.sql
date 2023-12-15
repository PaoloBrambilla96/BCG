DROP TABLE IF EXISTS electricity_table;

CREATE TABLE electricity_table (
    id_tot INTEGER PRIMARY KEY AUTOINCREMENT,
    data DATE,
    ora TIME,
    grp TEXT,
    strategy1 INTEGER,
    strategy2_1 INTEGER,
    strategy2_2 INTEGER,
    strategy2_3 INTEGER,
    strategy2_4 INTEGER,
    strategy2_5 INTEGER,
    strategy2_6 INTEGER,
    strategy3_1 BOOL,
    strategy3_2 BOOL,
    strategy4_1 INTEGER,
    strategy4_2 INTEGER,
    strategy4_3 INTEGER,
    strategy5_1 BOOL,
    strategy5_2 BOOL,
    strategy5_3 BOOL,
    strategy6 INTEGER,
    final_result DOUBLE
);
