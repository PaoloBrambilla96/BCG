import sqlite3
from datetime import datetime


def create_sqlite3_DB():
    connection = sqlite3.connect('autoparts/db/carparts.db')
    with open('autoparts/db/create_table_query.sql') as f:
        connection.executescript(f.read())
    connection.commit()
    connection.close()


def show_table():
    connection = sqlite3.connect('autoparts/db/carparts.db')
    connection.row_factory = sqlite3.Row
    data = connection.execute('SELECT * FROM carparts_table ORDER BY final_result ').fetchall()  # DESC limit ' + str(selected_n_lines)
    connection.close()
    return data


def new_sqlite3_data_line(date, time, group, in_data, res):
    connection = sqlite3.connect('autoparts/db/carparts.db')
    connection.row_factory = sqlite3.Row
    query = "INSERT INTO carparts_table(data, ora, grp, strategy1, strategy2_1, strategy2_2, strategy2_3, strategy2_4, strategy2_5, strategy2_6, strategy3_1, strategy3_2, strategy4_1, strategy4_2, strategy4_3, strategy5_1, strategy5_2, strategy5_3, strategy6, final_result) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?);"
    sql_data = (
        date,
        time,
        str(group),
        int(in_data[0]),
        int(in_data[1]),
        int(in_data[2]),
        int(in_data[3]),
        int(in_data[4]),
        int(in_data[5]),
        int(in_data[6]),
        bool(in_data[7]),
        bool(in_data[8]),
        int(in_data[9]),
        int(in_data[10]),
        int(in_data[11]),
        bool(in_data[12]),
        bool(in_data[13]),
        bool(in_data[14]),
        in_data[15],
        res
    )
    cursor = connection.cursor()
    cursor.execute(query, sql_data)
    connection.commit()
    cursor.close()
    connection.close()


if __name__ == "__main__":
    create_sqlite3_DB()