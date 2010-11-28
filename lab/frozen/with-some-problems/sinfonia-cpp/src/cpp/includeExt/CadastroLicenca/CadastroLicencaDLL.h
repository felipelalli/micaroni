#include "biblia/seguranca/CadastroLicenca.h"
using namespace biblia::seguranca;


CadastroLicenca cadastroLicenca;


bool  _stdcall dll_carregarLicencaInicial (char* buffer);

void _stdcall dll_gerarLicencaInicial (	char* buffer,
										char* serial,
										char* tipo,
										char* atualizacao,
										char* hashMacAddress,															
										char* diasRestantes);

bool _stdcall dll_carregarLicencaFuncionamento (char* buffer);

void _stdcall dll_gerarLicencaFuncionamento (	char* buffer,
												char* serial,
												char* tipo,
												char* atualizacao,
												char* diasRestantes);

void _stdcall dll_getSerial(char* serial);

void _stdcall  dll_getTipo(char* tipo);

void  _stdcall dll_getAtualizacao(char* atualizacao);

void  _stdcall dll_getHashMacAddress(char* hashMacAddress);

void  _stdcall dll_getDiasRestantes(char* diasRestantes);

void  _stdcall dll_getApostado(char* apostado);

void  _stdcall dll_getGanho(char* ganho);