#include <cwf/controller.h>
#include <cwf/cppwebapplication.h>
#include <cwf/urlencoder.h>
#include <cwf/sqldatabasestorage.h>
#include <cwf/sqlquery.h>

//CWF::SqlDatabaseStorage conexao("QPSQL", "localhost", "banco", "postgres", "1234", 5432);
CWF::SqlDatabaseStorage conexao("QPSQL", "localhost", "my_postgres_db", "postgres_user", "password", 5432);

class CepController : public CWF::Controller
{
public:
    void doDelete(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        QByteArray cep_value = request.getParameter("cep");
        response.write(qry.deleteRecord("logradouro", "logr_cep = '" + cep_value + "'"));
    }

    void doPut(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        QByteArray cep_value = request.getParameter("cep");
        response.write(qry.updateFromJson(request.bodyToJsonObject(), "logradouro", "logr_cep = '" + cep_value + "'"));
    }

    void doPost(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());
        response.write(qry.insertFromJson(request.bodyToJsonObject(), "logradouro"));
    }

    void doGet(CWF::Request &request, CWF::Response &response) const override
    {
        CWF::SqlQuery qry(conexao.getDatabase());

        if (request.getRequestURL() == "/cep") {
            QByteArray cep_value = request.getParameter("cep");

            if (!cep_value.isNull()) {
                qry.prepare("SELECT * FROM logradouro WHERE logr_cep = '" + cep_value + "'");
                if (qry.exec()["success"].toBool()) {
                    // TODO
                }
            }
        }

        response.write(qry.toJson());
    }
};

int main(int argc, char *argv[])
{
    CWF::CppWebApplication server(argc, argv, "/media/henrique/work/cursos/work/CEPController/server");
    server.addController<CepController>("/cep");
    return server.start();
}
