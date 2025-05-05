#include "stdafx.h"
using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
int main(array<System::String^>^ args)
{
	String^ cadenaConexion = "Data Source=localhost;Initial Catalog = Escuela; Integrated Security = True; ";
		SqlConnection ^ conexion = gcnew SqlConnection(cadenaConexion);
	try
	{
		conexion->Open();
		Console::WriteLine("Conexi�n exitosa a la base de datos.");
		String^ consulta = "SELECT * FROM Estudiantes";
		SqlCommand^ comando = gcnew SqlCommand(consulta, conexion);
		SqlDataReader^ lector = comando->ExecuteReader();
		while (lector->Read())
		{
			Console::WriteLine("ID: {0}, Nombre: {1}, Edad: {2}",
				lector["Id"], lector["Nombre"], lector["Edad"]);
		}
		conexion->Close();
	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Error: {0}", ex->Message);
	}
	Console::ReadLine();
	return 0;
}