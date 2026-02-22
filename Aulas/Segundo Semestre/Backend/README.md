# Backend – Desenvolvimento Web com ASP.NET Core

O objetivo é construir um sistema web completo para gerenciamento de dispositivos tecnológicos em ambientes educacionais, utilizando ASP.NET Core MVC com Entity Framework Core para integração com banco de dados, autenticação baseada em sessão e restrições de acesso por regras de perfil.

> **Nota:** Os projetos aqui presentes foram desenvolvidos em Visual Studio Code com .NET SDK. Como a execução depende do ambiente .NET, banco de dados (SQL Server) e configuração de conexão, o foco deste material é a demonstração da arquitetura MVC, segurança básica, consultas LINQ avançadas e integração real com banco de dados.

### Conceitos Fundamentais Aplicados

- Arquitetura MVC com separação clara: Models para domínio e regras de negócio, Controllers para lógica de orquestração e validações, Views para apresentação em Razor com CSS custom.
- Injeção de dependência para AppDbContext (EF Core) em todos os controllers.
- Autenticação e autorização: sessão para armazenamento de UsuarioId e Nome, restrição por RegraId (ex.: apenas professores acessam CRUD de dispositivos).
- Hash de senhas com SHA256 (byte[]) para armazenamento seguro.
- Upload e exibição de imagens: conversão de IFormFile para byte[] e Base64 para renderização inline.
- ViewModels personalizados para evitar exposição de entidades: DashboardViewModel para métricas agregadas, DispositivosViewModel para filtros e listas, EditarDispositivoViewModel para edição, PerfilViewModel para atualização de usuário.
- Entidades geradas por Scaffold DB First com relações 1:N (ex.: Usuario → Manutencaos, TipoDispositivo → Dispositivos).
- LINQ avançado para consultas complexas: Include para eager loading, Join + GroupBy + Select para agrupamentos, Any para verificações, Count condicional para totais.
- Filtros dinâmicos em consultas (busca Contains, Where por IDs nullable).
- CRUD completo com validações server-side (campos obrigatórios, senhas iguais, email único).
- Mensagens de feedback: ViewBag para erros imediatos, TempData para sucesso pós-redirecionamento.
- Frontend responsivo: CSS variables, grid layouts, media queries, neomorfismo, modais com JS nativo para upload/preview.
- Configuração do pipeline: AddDbContext, AddSession, UseSession, HTTPS redirection, routing padrão.

### Estrutura do Projeto

- **Controllers/**: CadastroController (registro com validações e hash), DashboardController (métricas com Join/GroupBy), DispositivosController (lista filtrada, edição, exclusão restrita), HomeController (verificação de acesso), LoginController (autenticação com sessão), PerfilController (edição de dados e upload de foto).
- **Models/**: Entidades Scaffold (Dispositivo, LocalDispositivo, Manutencao, RegraPerfil, TipoDispositivo, TipoManutencao, Usuario) + ViewModels (DashboardViewModel, DispositivosViewModel, EditarDispositivoViewModel, ItemAgrupado, PerfilViewModel).
- **Services/**: HashService (geração de hash SHA256).
- **Data/**: AppDbContext (DbContext com DbSets para entidades).
- **Views/**: Cadastro/Index (formulário de registro), Dashboard/Index (métricas e listas), Dispositivos/Index (tabela filtrável com CRUD), Dispositivos/Editar (form de edição com selects), Home/Index (landing page com seções), Login/Index (form de login), Perfil/Index (edição de perfil com modal de foto).
- **wwwroot/**: CSS (global.css, cadastro.css, dashboard.css, dispositivos.css, perfil.css, modal-foto.css, style.css) + JS (modal.js para preview/upload) + assets (ícones SVG, imagens).
- **Program.cs**: Configuração do builder (AddControllersWithViews, AddDbContext, AddSession), pipeline (UseSession, UseHttpsRedirection, UseRouting, UseAuthorization, MapControllerRoute).

### Comandos e Técnicas Principais

#### Configuração e Inicialização
- `builder.Services.AddControllersWithViews();`  
  Adiciona suporte a controllers e views.

- `builder.Services.AddDbContext<AppDbContext>(options => options.UseSqlServer(Configuration.GetConnectionString("ConexaoPadrao")));`  
  Configura EF Core com conexão SQL Server de appsettings.json.

- `builder.Services.AddSession();`  
  Ativa middleware de sessão.

- `app.UseSession();`  
  Habilita uso de sessão no request pipeline.

- `app.MapControllerRoute(name: "default", pattern: "{controller=Home}/{action=Index}/{id?}");`  
  Define rota padrão para controllers.

#### Segurança e Autenticação
- `HashService.GerarHashBytes(senha)`  
  Computa hash SHA256 de senha como byte[].

- `HttpContext.Session.SetInt32("UsuarioId", usuario.IdUsuario);`  
  Armazena ID do usuário na sessão após login.

- `HttpContext.Session.GetInt32("UsuarioId")`  
  Recupera ID para verificação de login.

- `HttpContext.Session.Clear();`  
  Limpa sessão para logout.

- `_context.Usuarios.Any(u => u.Email == email)`  
  Verifica se email já existe para evitar duplicatas.

- `usuario.Senha.SequenceEqual(senhaDigitadaHash)`  
  Compara hash de senha digitada com armazenada.

#### Consultas e Manipulação de Dados
- `_context.Dispositivos.Include(d => d.IdTipoDispositivoNavigation).Include(d => d.IdLocalNavigation).AsQueryable();`  
  Consulta com eager loading e mantém aberta para filtros.

- `_context.Dispositivos.Join(_context.TipoDispositivos, d => d.IdTipoDispositivo, t => t.IdTipoDispositivo, (d, t) => new { d, t.Nome }).GroupBy(item => item.Nome).Select(g => new ItemAgrupado { Nome = g.Key, Quantidade = g.Count() });`  
  Join e agrupamento para contagem de dispositivos por tipo.

- `_context.Dispositivos.Count(d => d.SituacaoOperacional == "Operando")`  
  Contagem condicional para totais (ativos, manutenção, inoperantes).

- `_context.Dispositivos.Where(d => d.Nome.Contains(busca)).Where(d => d.IdTipoDispositivo == tipoId.Value).Where(d => d.IdLocal == localId.Value);`  
  Filtros dinâmicos com Where chained.

- `_context.SaveChangesAsync();`  
  Persiste alterações assíncronas (edição, exclusão).

- `_context.Usuarios.FirstOrDefault(u => u.IdUsuario == id)`  
  Busca usuário por ID para perfil/dashboard.

- `_context.LocalDispositivos.OrderBy(l => l.Nome).ToList();`  
  Lista ordenada de locais.

#### Upload e Imagens
- `using (var ms = new MemoryStream()) { foto.CopyTo(ms); usuario.Foto = ms.ToArray(); }`  
  Converte IFormFile para byte[] e salva no banco.

- `Convert.ToBase64String(usuario.Foto)`  
  Converte byte[] para Base64 string.

- `data:image/*;base64,{Base64String}`  
  Formato URI para imagem inline na View.

#### Views e Frontend
- `@model ViewModelType`  
  Tipagem de modelo na View Razor.

- `@foreach (var item in Model.Lista) { ... }`  
  Loop para listas (dispositivos, tipos, locais, agrupamentos).

- `@if (ViewBag.Erro != null) { <p>@ViewBag.Erro</p> }`  
  Exibição de erros via ViewBag.

- `@if (TempData["Sucesso"] != null) { <div>@TempData["Sucesso"]</div> }`  
  Exibição de mensagens de sucesso via TempData.

- `<dialog id="modal-foto">... <script> preview JS </script>`  
  Modal nativo para upload/preview de foto.

- `onchange="this.form.submit()"`  
  Submit automático em selects para filtros.

- `onclick="return confirm('Mensagem?')"`  
  Confirmação JS para exclusão.

### Observações Finais

- O projeto Aurum Lab é um sistema para gerenciamento de inventário e manutenção de dispositivos em ambientes educacionais, com foco em segurança (hash, sessão), usabilidade (filtros, métricas) e restrições (perfil de professor para CRUD).
- Todas as operações usam EF Core para persistência e LINQ para consultas eficientes.
- Frontend é customizado com CSS variables, neomorfismo e responsividade via media queries.
- Nenhum framework frontend pesado (ex.: Bootstrap) – puro CSS + JS nativo.