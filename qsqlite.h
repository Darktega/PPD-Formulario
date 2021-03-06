#ifndef QSQLITE_H
#define QSQLITE_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

#include "patient.h"

class QSQLite {
    private:
        QString dbName;
        QSqlDatabase db;

    public:
        QSQLite();

        bool initializeSQLiteDB( QString );

        // Operaciones de soporte
        bool openDB();
        void closeDB();
        bool deleteDB();
        QSqlError lastError();

        int getNumberOfPatients();

        // Setup
        bool createPatientTable();
        bool createFootTable();

        // Operaciones básicas
        bool insertPatient( int, QString, int, QString, QString, QString, QString );
        bool insertFoot(int, QVector<unsigned int>);

        // Consultas
        Patient* getPatientById( int );
        Patient* getPatientByFileNumber( int );
        std::vector<Foot*> getFeetByPatientId( int );
        std::vector<Patient*> getAllPatients();
    };

#endif // QSQLITE_H
