# Google Java Formatting Setup

This document describes the Google Java Style formatting configuration for the Java project.

## 🎨 Formatting Tools Configured

### **1. Google Java Format (Standalone)**
- **Tool**: `google-java-format-1.18.1-all-deps.jar`
- **Location**: Downloaded automatically to `java/` directory
- **Style**: Google Java Style Guide
- **Indentation**: 2 spaces
- **Line Length**: 100 characters (Google default)

### **2. VS Code Integration**
- **Settings**: Configured in `.vscode/settings.json`
- **Auto-format**: Enabled on save for Java files
- **Import organization**: Automatic
- **Style URL**: Google Style Guide XML configuration

### **3. Maven Plugin (Note: Compatibility Issues)**
- **Plugin**: `com.coveo:fmt-maven-plugin:2.13`
- **Status**: ⚠️ Has compatibility issues with Java 21+
- **Alternative**: Use standalone formatter

## 🚀 How to Format Java Code

### **Method 1: Automatic (VS Code)**
- Files automatically format on save
- Import statements are organized automatically
- Uses Google Java Style Guide

### **Method 2: Script (Recommended)**
```bash
# Format all Java files
cd java/
./format_java.sh

# Format specific file
./format_java.sh src/main/java/practice/HelloWorld.java

# Format specific directory
./format_java.sh src/main/java/practice/
```

### **Method 3: Direct Command**
```bash
# Format single file
java -jar google-java-format.jar --replace path/to/File.java

# Format all files in directory
find src/main/java -name "*.java" | xargs java -jar google-java-format.jar --replace
```

## 🔧 Configuration Details

### **VS Code Settings** (`.vscode/settings.json`)
```json
{
  "java.format.settings.url": "https://raw.githubusercontent.com/google/styleguide/gh-pages/eclipse-java-google-style.xml",
  "java.format.settings.profile": "GoogleStyle",
  "java.format.enabled": true,
  "[java]": {
    "editor.tabSize": 2,
    "editor.defaultFormatter": "redhat.java",
    "editor.formatOnSave": true,
    "editor.codeActionsOnSave": {
      "source.organizeImports": "explicit"
    }
  }
}
```

### **Maven Configuration** (`pom.xml`)
```xml
<plugin>
  <groupId>com.coveo</groupId>
  <artifactId>fmt-maven-plugin</artifactId>
  <version>2.13</version>
  <configuration>
    <style>google</style>
    <verbose>true</verbose>
  </configuration>
</plugin>
```

## 📋 Style Guide Summary

### **Google Java Style Key Points:**
- **Indentation**: 2 spaces (no tabs)
- **Line Length**: 100 characters
- **Braces**: K&R style (opening brace on same line)
- **Imports**: Organized automatically
- **Javadoc**: `/** */` for classes and public methods
- **Naming**: camelCase for methods/variables, PascalCase for classes

### **Example Formatted Code:**
```java
package practice;

/** Simple Hello World program in Java */
public class HelloWorld {
  public static void main(String[] args) {
    System.out.println("Hello, World!");
    
    if (args.length > 0) {
      System.out.println("Arguments provided:");
      for (int i = 0; i < args.length; i++) {
        System.out.println("  arg[" + i + "] = " + args[i]);
      }
    }
  }
}
```

## ✅ Verification

### **Test Formatting:**
```bash
# Run the format script
./format_java.sh

# Verify code still compiles and runs
./run_java.sh practice.HelloWorld "test" "args"
```

### **Features Working:**
- ✅ **Automatic formatting** on save in VS Code
- ✅ **Standalone formatter** via script
- ✅ **Import organization**
- ✅ **Google Style compliance**
- ✅ **Code compilation** after formatting
- ⚠️ **Maven plugin** (compatibility issues with Java 21+)

## 🔗 Resources

- [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
- [google-java-format GitHub](https://github.com/google/google-java-format)
- [VS Code Java Extension Pack](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack)

Google Java Style formatting is now configured and working! 🎯☕