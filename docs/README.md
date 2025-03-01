# Picol Documentation

This directory contains the documentation for the Picol interpreter.

## Local Development

To test this documentation site locally:

1. Install Ruby and Bundler
2. Run `bundle install` to install dependencies
3. Run `bundle exec jekyll serve` to start the local server
4. Visit `http://localhost:4000` in your browser

## Structure

- `index.md`: Home page
- `_config.yml`: Jekyll configuration
- `_layouts/`: Custom layouts
- `assets/`: CSS, images, and other resources
- Other `.md` files: Documentation content

## Adding Content

1. Create a new Markdown file
2. Add front matter at the top:
   ```yaml
   ---
   layout: default
   title: Your Page Title
   ---
   ```
3. Add your content using Markdown

## Mermaid Diagrams

Mermaid diagrams are supported. Wrap your Mermaid syntax in:

