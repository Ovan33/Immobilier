#include "Bien.h"

//Bien::Bien(QObject *parent) :
//    QObject(parent)
//{
//}

Bien::Bien(unsigned int prix, QDate &date, unsigned int surfHab, unsigned int surfJar, Ville *ville, Client *client)
{
    this->m_prixVente = prix;
    this->m_dateMiseVente = date;
    this->m_surfaceHabitable = surfHab;
    this->m_surfaceJardin = surfJar;
    this->m_ville = ville;
    this->m_client = client;
}

Bien::Bien(unsigned int numB, unsigned int prix, QDate &date, unsigned int surfHab, unsigned int surfJar, Ville *ville, Client *client)
{
    this->m_num = numB;
    this->m_prixVente = prix;
    this->m_dateMiseVente = date;
    this->m_surfaceHabitable = surfHab;
    this->m_surfaceJardin = surfJar;
    this->m_ville = ville;
    this->m_client = client;
}

void Bien::setPrix(unsigned int prix)
{
    this->m_prixVente = prix;
}

void Bien::setDate(QDate date)
{
    this->m_dateMiseVente = date;
}

int Bien::getPrix()
{
    return this->m_prixVente;
}

QDate Bien::getDate()
{
    return this->m_dateMiseVente;
}

Client* Bien::getClient()
{
    return this->m_client;
}

Ville* Bien::getVille()
{
    return this->m_ville;
}

int Bien::getSurfHabitable()
{
    return this->m_surfaceHabitable;
}

int Bien::getSurfJardin()
{
    return this->m_surfaceJardin;
}

void Bien::setSurfHabitable(int surf)
{
    this->m_surfaceHabitable = surf;
}

void Bien::setSurfJardin(int surf)
{
    this->m_surfaceJardin = surf;
}

bool Bien::sauvegarder()
{
    m_db = new BDD();
    bool res;
    if (m_db->ouvrir())
    {
        QSqlQuery requete(m_db->getDb());
        // debug infos
        qDebug()    << "NumBien : " << this->m_num << endl
                    << "Mise en vente : " << this->m_dateMiseVente.toString() << endl
                    << "NumClient : " << this->m_client->getNum() << endl
                    << "NumVille : "<< this->m_ville->getNum() << endl;
        // debug info
        switch(this->m_num)
        {
        case (0):
            requete.prepare("INSERT INTO biens VALUES(default,:numVille,:numClient,:prixVente,:dateVente,:surfHab,:surfJard)");
            requete.bindValue(":numVille",this->m_ville->getNum());
            requete.bindValue(":numClient", this->m_client->getNum());
            requete.bindValue(":prixVente",this->m_prixVente);
            requete.bindValue(":dateVente",this->m_dateMiseVente);
            requete.bindValue(":surfHab",this->m_surfaceHabitable);
            requete.bindValue(":surfJard", this->m_surfaceJardin);
            break;
        default:
            requete.prepare("update biens set num_v=:numVille,num_c=:numClient,prix_vente_b=:prixVente,date_mise_en_vente_b=:dateVente,surface_hab_b=:surfHab,surface_jardin_b=:surfJard where num_b=:numB");
            requete.bindValue(":numVille",this->m_ville->getNum());
            requete.bindValue(":numClient", this->m_client->getNum());
            requete.bindValue(":prixVente",this->m_prixVente);
            requete.bindValue(":dateVente",this->m_dateMiseVente);
            requete.bindValue(":surfHab",this->m_surfaceHabitable);
            requete.bindValue(":surfJard", this->m_surfaceJardin);
            requete.bindValue(":numB",this->m_num);
        }
        if (requete.exec())
            res = true;
        else
            res = false;
    }
    return res;
    m_db->close();
}
