document.addEventListener('DOMContentLoaded', function() {
  mermaid.initialize({
    startOnLoad: true,
    theme: 'dark',
    securityLevel: 'loose',
    flowchart: { 
      useMaxWidth: true,
      htmlLabels: true
    }
  });
});
