CREATE DATABASE HospitalDB; 
USE HospitalDB;

CREATE TABLE Room(
    RoomNo INT PRIMARY KEY CHECK (RoomNo BETWEEN 100 AND 999),
    RoomPhone VARCHAR(8),
    RoomRate DECIMAL(10,2) CHECK (RoomRate >= 30.00 AND RoomRate <= 100.00)
):

CREATE TABLE Treatment(
    TreatID INT PRIMARY KEY,
    TreatDesc VARCHAR(200),
    TreatCost DECIMAL(10,2) CHECK (TreatCost >= 50.00) 
);

CREATE TABLE Department(
    DeptID INT PRIMARY KEY,
    DeptSupervisorID INT,
);

CREATE TABLE Physician (
    PhysID INT PRIMARY KEY,
    PhysName VARCHAR(50) NOT NULL,
    PhysDept INT,
    TreatID INT,
    FOREIGN KEY (PhysDept) REFERENCES Department(DeptID),
    FOREIGN KEY (TreatID) REFERENCES Treatment(TreatID) 
);

ALTER TABLE Department
ADD FOREIGN KEY (DeptSupervisorID) REFERENCES Physician(PhysID);

CREATE TABLE Patient(
    Patient INT PRIMARY KEY,
    PatientName VARCHAR(50) NOT NULL, 
    PatientAddress VARCHAR(200) NOT NULL,
    AdmitDate DATE,
    HospitalStayDays INT CHECK (HospitalStayDays >= 0),
    AmountOwing DECIMAL(10,2),
    PhysID INT,
    RoomNo INT, 
    FOREIGN KEY (PhysID) REFERENCES Physician(PhysID),
    FOREIGN KEY (RoomNo) REFERENCES Room(RoomNo)
);
