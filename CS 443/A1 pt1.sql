CREATE DATABASE ProductDB; 
USE ProductDB;

CREATE TABLE Product(
    ProductID INT PRIMARY KEY,
    ProductDescription VARCHAR(200) 
  );
CREATE TABLE Item(
  ItemNum INT PRIMARYKEY 
  ItemDescription VARCHAR(200),
  CHECK (ItemNum IS NOT NULL)
);

CREATE TABLE Product_Item(
    ProductID INT,
    ItemNum INT, 
    QuantityUsed INT CHECK (QuantityUsed >= 0),
    PRIMARY KEY (ProductID, ItemNum) 
    FOREIGN KEY (ProductID, ItemNum) REFERENCES Product(ProductID),
    FOREIGN KEY (ItemNum) REFERENCES Item(itemNum)
);

CREATE TABLE Receipt (
    ReceiptNumber INT PRIMARY KEY,
    SalesDate DATE 
);

CREATE TABLE Sales(
    ReceiptNumber INT, 
    ProductID INT, ItemNumQuantitySold INT CHECK (QuantitySold >= 0),
    PRIMARY KEY (ReceiptNumber, ProductID),
    FOREIGN KEY (ReceiptNumber) REFERENCES Receipt(ReceiptNumber),
    FOREIGN KEY (ProductID) REFERENCES Product(ProductID)
);
