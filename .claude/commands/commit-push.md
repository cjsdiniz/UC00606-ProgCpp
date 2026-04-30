# Commit e Push para GitHub

Faz commit de todas as alterações pendentes e push para o repositório remoto no GitHub.

## Instruções

1. Corre `git status` para ver o estado actual do repositório.
2. Se não houver alterações para commitar, informa o utilizador e para.
3. Mostra o diff (`git diff`) das alterações não staged e staged para que o utilizador as possa rever.
4. Pede ao utilizador uma mensagem de commit descritiva (ou usa `$ARGUMENTS` se foi fornecida como argumento ao comando).
5. Faz stage de todos os ficheiros modificados e novos relevantes com `git add` (evita ficheiros sensíveis como `.env`).
6. Cria o commit com a mensagem fornecida.
7. Faz `git push origin main` (ou o branch actual).
8. Confirma o sucesso mostrando o URL do repositório no GitHub.

## Notas

- Se `$ARGUMENTS` contiver uma mensagem de commit, usa-a directamente sem pedir ao utilizador.
- Usa sempre `https://` como protocolo (não SSH), pois este projecto está configurado com HTTPS.
- O repositório remoto é `https://github.com/cjsdiniz/UC00606-ProgC--`.
