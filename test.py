from github import Github
import os

# --- Function Dependencies (Stub `generate_pr_description`) ---

def generate_pr_description(report):
    return "This is a test pull request generated for report:\n" + "\n".join(str(item) for item in report)

# --- Main Function (Paste your original code) ---

def create_remediation_pr(repo_url, head_branch, base_branch, report) -> str:
    description = generate_pr_description(report)

    github_token = os.getenv("GITHUB_TOKEN")  
    if not github_token:
        raise ValueError("GitHub token not found in environment variables. Set GITHUB_TOKEN.")

    global g, github_url
    g = Github(github_token)
    github_url = "https://github.com/"

    # Get the repository
    repo_name = repo_url.replace(github_url, "").replace(".git", "")
    repo = g.get_repo(repo_name)

    # Check if any dictionary in the report contains the 'requirement' attribute
    contains_requirement = any('requirement' in item for item in report)
    if contains_requirement:
        pr_title = "Code change for the given requirement with AI:"
    else:
        pr_title = "Code scan issue remediation with AI:"
    
    pulls = repo.get_pulls(head=head_branch, base=base_branch, state='open')
    print(pulls.totalCount)
    if pulls.totalCount > 0:
        for pull in pulls:
            pull.edit(title=pr_title, body=description)
            return pull.html_url

    # Create a pull request
    pr_title = pr_title + f"  {head_branch} -> {base_branch}"
    pr_body = description
    pr = repo.create_pull(
        title=pr_title,
        body=pr_body,
        head=head_branch,
        base=base_branch
    )
    return pr.html_url

# --- Test Call ---



if __name__ == "__main__":
    repo_url = "https://github.com/vishalkumar437/practice.git"
    head_branch = "branch-tes"
    base_branch = "main"
    report = [
        {"file": "main.py", "issue": "Unused variable", "requirement": "Refactor the class"},
        {"file": "utils.py", "issue": "Deprecated class usage"}
    ]

    try:
        pr_url = create_remediation_pr(repo_url, head_branch, base_branch, report)
        print(f"Pull request created or updated: {pr_url}")
    except Exception as e:
        print(f"Error: {e}")
