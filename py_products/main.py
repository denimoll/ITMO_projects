import sqlite3
import sys

conn = sqlite3.connect("products.db")
cursor = conn.cursor()

def check(product):
    sql = "select * from products where name='%s'" % product
    cursor.execute(sql)
    if (cursor.fetchall()):
        return 1
    else:
        return 0

def product_add(product, count, count_type):
    if (not check(product)):
        item = [(product, count, count_type)]
        cursor.executemany("INSERT INTO products VALUES (?,?,?)", item)
    else:
        print("Такой продукт уже существует")
    conn.commit()

def product_remove(product):
    if (check(product)):
        sql = "DELETE FROM products WHERE name='%s'" % product
        cursor.execute(sql)
    else:
        print("Такого продукта не существует")
    conn.commit()

def product_update(product, count):
    if (check(product)):
        sql = "update products set count='%s' where name='%s'" % (count, product)
        cursor.execute(sql)
    else:
        print("Такого продукта не существует")
    conn.commit()


if (sys.argv[1] == "new"):
    conn = sqlite3.connect("products_new.db")
    cursor = conn.cursor()
    cursor.execute("CREATE TABLE products(name text, count int, count_type text)")
    print("Была создана новая БД products_new.db с чистым списком продуктов")
    sys.exit()
elif (sys.argv[1] == "list"):
    cursor.execute("select * from products")
    for item in cursor.fetchall():
        print(item)
    sys.exit()
elif (sys.argv[1] == "add"):
    product_add(sys.argv[2], sys.argv[3], sys.argv[4])
elif (sys.argv[1] == "remove"):
    product_remove(sys.argv[2])
elif (sys.argv[1] == "update"):
    product_update(sys.argv[3], sys.argv[2])
else:
    print("You can add, remove or update products in the Table. Or create new DataBase")
